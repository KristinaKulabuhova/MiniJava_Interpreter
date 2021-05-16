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

    class MainClass;
    class MethodDeclaration;
    class MethodInvocation;

    class VariableDeclaration;

    class VarTypeStr;
    class SimpleType;

    class Scanner;
    class Driver;

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
    #include "ExecBlocks/If.h"
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
  
    #include "Expressions/TrueExpr.h"
//   #include "Expressions/VarExpr.h"
    #include "Expressions/VarType.h"
    #include "Expressions/SimpleType.h"
    #include "SubsidiaryClasses/ExprList.h"
    #include "MainElements/MethodInvocation.h"



    
    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& /*driver*/) {
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
%nterm <VarTypeStr*> type
%nterm <SimpleType*> simple_type
%nterm <ExecCode*> statement_list
%nterm <BaseExecBlock*> statement
%nterm <MethodInvocation*> method_invocation
%nterm <ExprList*> expr_list
%nterm <BaseExpr*> expr
%nterm <FieldExpr*> field_invocation

//%printer { yyo << $$; } <*>;

%%
%left "+" "-" "*" "/" "%" "<" "<=" ">" ">=" "==" "!=" "||" "&&" "." "!" "[";
%right ")" "else";

%start unit;

unit: program { driver.program = $1; };

program: main_class class_declaration_list { $$ = new Program($1, $2); }

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statement_list "}" "}" { $$ = new MainClass($2, $11, driver.location); };

class_declaration_list: class_declaration_list class_declaration 	{ $$ = $1; $$->addClass($2); }
					  | %empty 			{ $$ = new ClassDeclarationList(driver.location); }

class_declaration:   "class" "identifier" "extends" "identifier" "{" declaration_list "}"  	{ $$ = new Class($2, $4, driver.location); $$->initialize($6); }
		         | "class" "identifier" "{" declaration_list "}" 			{ $$ = new Class($2, "", driver.location); $$->initialize($4); }

declaration_list: declaration_list variable_declaration 	{ $$ = $1; $$->addDecl($2); }
		  | declaration_list method_declaration         { $$ = $1; $$->addDecl($2); }
		  | %empty 				        { $$ = new DeclarationList(driver.location); }

method_declaration: "public" type "identifier" "(" formals ")" "{" statement_list "}"		{ $$ = new MethodDeclaration($3, $5, $2, $8, driver.location); }
		          | "public" type "identifier" "(" ")" "{" statement_list "}"		{ $$ = new MethodDeclaration($3, nullptr, $2, $7, driver.location); }

variable_declaration: type "identifier" ";"	{ $$ = new VariableDeclaration($1, $2, driver.location); }

formals: type "identifier"			{ $1->GetName() = $2; $$ = new Formals($1, driver.location); }
	   | formals "," type "identifier"	{ $$ = $1; $3->GetName() = $4; $$->addVar($3); }

type: simple_type		 { $$ = new VarTypeStr($1, false); }
	| simple_type "[]"	 { $$ = new VarTypeStr($1, true); }

simple_type:"int" 		{ $$ = new SimpleType(0, ""); }
	      | "boolean" 	{ $$ = new SimpleType(1, ""); }
	      | "void" 		{ $$ = new SimpleType(2, ""); }
	      | "identifier" 	{ $$ = new SimpleType(3, $1); }

statement_list:   statement_list statement	{ $$ = $1; $$->addBaseBlock($2); }
		      | %empty			{ $$ = new ExecCode(driver.location); }

statement: "assert" "(" expr ")" ";" 				{ $$ = new AssertExpr($3, driver.location); }
    	 | variable_declaration 				{ $$ = $1; }
         | "{" statement_list "}"  				{ $$ = new Block($2, driver.location); }
         | "if"  "(" expr ")" statement   			{ $$ = new If($3, $5, nullptr, driver.location); }
         | "if"  "(" expr ")" statement "else" statement 	{ $$ = new If($3, $5, $7, driver.location); }
         | "while"  "(" expr ")" statement 			{ $$ = new While($3, $5, driver.location); }
         | "System" "." "out" "." "println" "(" expr ")" ";"  	{ $$ = new Println($7, driver.location); }
         | "identifier" "=" expr ";" 				{ $$ = new Assignment(new IdentExpr($1, driver.location), $3, driver.location); }
         | "return" expr ";"  					{ $$ = new Return($2, driver.location); }
         | method_invocation ";"	 			{ $$ = $1; }

method_invocation:   expr "." "identifier" "(" ")"		{ $$ = new MethodInvocation($1, $3, nullptr, driver.location); }
		   | expr "." "identifier" "(" expr_list ")"	{ $$ = new MethodInvocation($1, $3, $5, driver.location); }
          	   | field_invocation "(" ")"			{ $$ = new MethodInvocation($1, nullptr, driver.location); }
		   | field_invocation "(" expr_list ")"		{ $$ = new MethodInvocation($1, $3, driver.location); }

field_invocation: "this" "." "identifier"			 { $$ = new FieldExpr($3, driver.location); }

expr_list: expr			                { $$ = new ExprList($1, driver.location); }
	     | expr_list "," expr 	        { $$ = $1; $$->addExpr($3);}

expr: expr "&&" expr  			        { $$ = new AndExpr($1, $3, driver.location); }
	| expr "||" expr			{ $$ = new OrExpr($1, $3, driver.location); }
	| expr "<" expr				{ $$ = new LessExpr($1, $3, driver.location); }
	| expr ">" expr				{ $$ = new GreaterExpr($1, $3, driver.location); }
	| expr ">=" expr			{ $$ = new GEqExpr($1, $3, driver.location); }
	| expr "!=" expr			{ $$ = new NEqExpr($1, $3, driver.location); }
	| expr "<=" expr			{ $$ = new LEqExpr($1, $3, driver.location); }
	| expr "==" expr   			{ $$ = new EqExpr($1, $3, driver.location); }
	| expr "+" expr    			{ $$ = new AddExpr($1, $3, driver.location); }
	| expr "-" expr     		        { $$ = new SubtractExpr($1, $3, driver.location); }
	| expr "*" expr  			{ $$ = new MulExpr($1, $3, driver.location); }
	| expr "/" expr  			{ $$ = new DivExpr($1, $3, driver.location); }
	| expr "%" expr  			{ $$ = new ModExpr($1, $3, driver.location); }
	| expr "[" expr "]"			{ $$ = new AtExpr($1, $3, driver.location); }
	| expr "." "length"    			{ $$ = new LengthExpr($1, driver.location); }
	| "new" simple_type "[" expr "]"	{ $$ = new NewArrExpr($2, $4, driver.location); }
	| "new" "identifier" "(" ")"		{ $$ = new NewCustomVarExpr($2, driver.location); }
	| "identifier"				{ $$ = new IdentExpr($1, driver.location);}
	| "number"				{ $$ = new NumExpr($1, driver.location); }
	| "true"				{ $$ = new TrueExpr(driver.location); }
	| "false"				{ $$ = new FalseExpr(driver.location); }
	| method_invocation			{ $$ = $1; }
	| field_invocation			{ $$ = $1; }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
