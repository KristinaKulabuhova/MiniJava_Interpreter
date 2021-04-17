%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    class Program;

    class BaseExecBlock;

    class Class;
    class ClassDeclarationList;
    class DeclarationList;
    class ExecCode;
    class BaseExpr;

    class ExprList;
    class FieldExpr;
    class Formals;

    class Lvalue;
    class MainClass;
    class MethodDeclaration;
    class MethodInvocation;

    class VariableDeclaration;

    class Scanner;
    class Driver;

    enum VarType {
      int_t,
      bool_t,
      void_t,
      custom_t
    };

    #define VARTYPE

    struct VarTypeStr {
        VarType type{int_t};
        bool array{false};
        explicit VarTypeStr(VarType type = void_t, bool array = false) : type(type), array(array) {}
    };

    #define VARTYPESTR
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "ExecBlocks/AssertExpr.h"
    #include "ExecBlocks/Assignment.h"
    #include "ExecBlocks/Block.h"
    #include "ExecBlocks/ExecCode.h"
    #include "ExecBlocks/For.h"
    #include "ExecBlocks/If.h"
    #include "ExecBlocks/Lvalue.h"
    #include "ExecBlocks/MethodDeclaration.h"
    #include "ExecBlocks/VariableDeclaration.h"
    #include "ExecBlocks/Println.h"
    #include "ExecBlocks/Return.h"
    #include "ExecBlocks/While.h"

    #include "Expressions/AddExpr.h"
    #include "Expressions/AndExpr.h"
    #include "Expressions/AtExpr.h"
    #include "Expressions/DivExpr.h"
    #include "Expressions/EqExpr.h"
    #include "Expressions/FalseExpr.h"
    #include "Expressions/FieldExpr.h"
    #include "Expressions/GEqExpr.h"
    #include "Expressions/GreaterExpr.h"
    #include "Expressions/IdentExpr.h"
    #include "Expressions/LengthExpr.h"
    #include "Expressions/LEqExpr.h"
    #include "Expressions/LessExpr.h"
    #include "Expressions/ModExpr.h"
    #include "Expressions/MulExpr.h"
    #include "Expressions/NEqExpr.h"
    #include "Expressions/NewArrExpr.h"
    #include "Expressions/NewCustomVarExpr.h"
    #include "Expressions/NotExpr.h"
    #include "Expressions/NumExpr.h"
    #include "Expressions/OrExpr.h"
    #include "Expressions/SubtractExpr.h"
    #include "Expressions/ThisExpr.h"
    #include "Expressions/TrueExpr.h"
    #include "Expressions/VarExpr.h"
    #include "SubsidiaryClasses/ExprList.h"
    #include "MainElements/MethodInvocation.h"



    
    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    FILEEND 0 "end of file"
   
    CLASS 	"class"
    PUBLIC 	"public"
    STATIC 	"static"
    EXTENDS     "extends"
    FALSE 	"false"
    TRUE 	"true"
    
    NEW 	"new"
    OUT 	"out"
    MAIN 	"main"
    ASSERT 	"assert"
    THIS 	"this"
    PRINTLN     "println"
    SYSTEM 	"System"
    LENGTH 	"length"
    
    VOID 	"void"
    INT 	"int"
    BOOLEAN     "boolean"
    RETURN 	"return"

    LROUND 	"("
    RROUND 	")"
    LCURLY 	"{"
    RCURLY 	"}"
    LSQUARE     "["
    RSQUARE     "]"
    BRACKS 	"[]"

    WHILE 	"while"
    IF 		"if"
    ELSE 	"else"

    COMMA 	","
    SEMICOLON   ";"
    DOT 	"."

    AND 	"&&"
    OR          "||"
    EQ 		"=="
    NEQ 	"!="
    NEG 	"!"
    GEQ 	">="
    LEQ 	"<="
    GREATER     ">"
    LESS 	"<"
    ASSIGN 	"=" 
    
    PLUS 	"+"
    MINUS 	"-"
    SLASH 	"/"
    MODUL 	"%"
    STAR 	"*"
;

%token <std::string> IDENTIFIER "identifier"
%token <std::string> NUM "number"

%nterm <Program*> program
%nterm <MainClass*> main_class
%nterm <ClassDeclarationList*> class_declaration_list
%nterm <Class*> class_declaration
%nterm <DeclarationList*> declaration_list
%nterm <MethodDeclaration*> method_declaration
%nterm <VariableDeclaration*> variable_declaration
%nterm <Formals*> formals
%nterm <VarTypeStr> type
%nterm <VarType> simple_type
%nterm <ExecCode*> statement_list
%nterm <BaseExecBlock*> statement
%nterm <MethodInvocation*> method_invocation
%nterm <ExprList*> expr_list
%nterm <Lvalue*> lvalue
%nterm <BaseExpr*> expr
%nterm <FieldExpr*> field_invocation

//%printer { yyo << $$; } <*>;

%%

%left "+" "-";
%left "||" "&&";
%left "<" "<=" ">=" "==" "!=" ">";
%left "*" "/" "%";
%right "!";

%start unit;

unit: program { driver.program = $1; };

program: main_class class_declaration_list { $$ = new Program($1, $2); }

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statement_list "}" "}" { $$ = new MainClass($2, $11); };

class_declaration_list: class_declaration_list class_declaration 	{ $$ = $1; $$->addClass($2); }
					  | %empty 			{ $$ = new ClassDeclarationList(); }

class_declaration:   "class" "identifier" "extends" "identifier" "{" declaration_list "}"  	{ $$ = new Class($2, $4); $$->initialize($6); }
		         | "class" "identifier" "{" declaration_list "}" 			{ $$ = new Class($2, nullptr); $$->initialize($4); }

declaration_list: declaration_list variable_declaration 	{ $$ = $1; $$->addDecl($2); }
		  | declaration_list method_declaration         { $$ = $1; $$->addDecl($2); }
		  | %empty 				        { $$ = new DeclarationList(); }

method_declaration: "public" type "identifier" "(" formals ")" "{" statement_list "}"		{ $$ = new MethodDeclaration($3, $5, $2, $8); }
		          | "public" type "identifier" "(" ")" "{" statement_list "}"		{ $$ = new MethodDeclaration($3, nullptr, $2, $7); }

variable_declaration: type "identifier" ";"	{ $$ = new VariableDeclaration($1, $2); }

formals: type "identifier"			{ $$ = new Formals($1, $2); }
	   | formals "," type "identifier"	{ $$ = $1, $$->addVar($3, $4); }

type: simple_type		 { $$ = VarTypeStr($1); }
	| simple_type "[]"	 { $$ = VarTypeStr($1, true); }

simple_type:    "int" 		{ $$ = int_t; }
	      | "boolean" 	{ $$ = bool_t; }
	      | "void" 		{ $$ = void_t; }
	      | "identifier" 	{ $$ = custom_t; }

statement_list:   statement_list statement	{ $$ = $1; $$->addBaseBlock($2); }
		      | %empty			{ $$ = new ExecCode(); }

statement: "assert" "(" expr ")" ";" 				{ $$ = new AssertExpr($3); }
    	 | variable_declaration 				{ $$ = $1; }
         | "{" statement_list "}"  				{ $$ = new Block($2); }
         | "if"  "(" expr ")" statement   			{ $$ = new If($3, $5); }
         | "if"  "(" expr ")" statement "else" statement 	{ $$ = new If($3, $5, $7); }
         | "while"  "(" expr ")" statement 			{ $$ = new While($3, $5); }
         | "System" "." "out" "." "println" "(" expr ")" ";"  	{ $$ = new Println($7); }
         | lvalue "=" expr ";" 					{ $$ = new Assignment($1, $3); }
         | "return" expr ";"  					{ $$ = new Return($2); }
         | method_invocation ";"	 			{ $$ = $1; }

lvalue: "identifier"			{ $$ = new Lvalue(new VarExpr($1)); }
       | "identifier" "[" expr "]"	{ $$ = new Lvalue(new VarExpr($1, $3)); }
       | field_invocation		{ $$ = new Lvalue($1); }

method_invocation:   expr "." "identifier" "(" ")"		{ $$ = new MethodInvocation($1, $3, nullptr); }
		   | expr "." "identifier" "(" expr_list ")"	{ $$ = new MethodInvocation($1, $3, $5); }

field_invocation: "this" "." "identifier"			 { $$ = new FieldExpr($3); }
		        | "this" "." "identifier" "[" expr "]"	{ $$ = new FieldExpr($3, $5); }

expr_list: expr			                { $$ = new ExprList($1); }
	     | expr_list "," expr 	        { $$ = $1; $$->addExpr($3);}

expr: expr "&&" expr  			        { $$ = new AndExpr($1, $3); }
	| expr "||" expr			{ $$ = new OrExpr($1, $3); }
	| expr "<" expr				{ $$ = new LessExpr($1, $3); }
	| expr ">" expr				{ $$ = new GreaterExpr($1, $3); }
	| expr ">=" expr			{ $$ = new GEqExpr($1, $3); }
	| expr "!=" expr			{ $$ = new NEqExpr($1, $3); }
	| expr "<=" expr			{ $$ = new LEqExpr($1, $3); }
	| expr "==" expr   			{ $$ = new EqExpr($1, $3); }
	| expr "+" expr    			{ $$ = new AddExpr($1, $3); }
	| expr "-" expr     		        { $$ = new SubtractExpr($1, $3); }
	| expr "*" expr  			{ $$ = new MulExpr($1, $3); }
	| expr "/" expr  			{ $$ = new DivExpr($1, $3); }
	| expr "%" expr  			{ $$ = new ModExpr($1, $3); }
	| expr "[" expr "]"			{ $$ = new AtExpr($1, $3); }
	| expr "." "length"    			{ $$ = new LengthExpr($1); }
	| "new" simple_type "[" expr "]"	{ $$ = new NewArrExpr($2, $4); }
	| "new" "identifier" "(" ")"		{ $$ = new NewCustomVarExpr($2); }
	| "identifier"				{ $$ = new VarExpr($1);}
	| "identifier" "[" expr "]" 		{ $$ = new VarExpr($1, $3); }
	| "number"				{ $$ = new NumExpr($1); }
	| "this"				{ $$ = new ThisExpr(); }
	| "true"				{ $$ = new TrueExpr(); }
	| "false"				{ $$ = new FalseExpr(); }
	| method_invocation			{ $$ = $1; }
	| field_invocation			{ $$ = $1; }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
