%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    class Program;
	...
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    
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
	EXTENDS "extends"

	FALSE 	"false"
	TRUE 	"true"
	NEW 	"new"
	OUT 	"out"
	MAIN 	"main"
	ASSERT 	"assert"
	THIS 	"this"
	PRINTLN "println"
	SYSTEM 	"System"
	LENGTH 	"length"

	VOID 	"void"
	INT 	"int"
	BOOLEAN "boolean"
	RETURN 	"return"

	LROUND 	"("
	RROUND 	")"
	LCURLY 	"{"
	RCURLY 	"}"
	LSQUARE "["
	RSQUARE "]"
	BRACKS 	"[]"

	WHILE 	"while"
	IF 		"if"
	ELSE 	"else"

	COMMA 	","
    SEMICOLON ";"
    DOT 	"."

	AND 	"&&"
	OR 		"||"
    EQ 		"=="
	NEQ 	"!="
	NEG 	"!"
	GEQ 	">="
	LEQ 	"<="
	GREATER ">"
    LESS 	"<"
    ASSIGN 	"=" 
    
	PLUS 	"+"
	MINUS 	"-"
    SLASH 	"/"
    MODUL 	"%"
    STAR 	"*"
;

%token <std::string> IDENTIFIER "identifier"
%token <std::string> INT "int"

%nterm <Program*> program
%nterm <MainClass*> main_class
%nterm <ClassDeclarationList*> class_declaration_list
%nterm <ClassDeclaration*> class_declaration
%nterm <DeclarationList*> declaration_list
%nterm <Declaration*> declaration
%nterm <MethodDeclaration*> method_declaration
%nterm <VariableDeclaration*> variable_declaration
%nterm <Formals*> formals
%nterm <Type*> type
%nterm <SimpleType*> simple_type
%nterm <StatementList*> statement_list
%nterm <Statement*> statement
%nterm <MethodInvocation*> method_invocation
%nterm <CallExpr*> call_expr
%nterm <ExprList*> expr_list
%nterm <Lvalue*> lvalue
%nterm <Expr*> expr

//%printer { yyo << $$; } <*>;

%%

%left "+" "-";
%left "||" "&&";
%left "<" "<=" ">=" "==" "!=" ">"
%left "*" "/" "%";
%right "!";

%start program;

program: main_class class_declaration_list

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statement "}" "}"

class_declaration_list: class_declaration_list class_declaration
					  | %empty

class_declaration: "class" "identifier" "extends" "identifier" "{" declaration_list "}"
				 | "class" "identifier" "{" declaration_list "}"

declaration_list: declaration_list declaration
				| %empty

declaration: variable_declaration
		   | method_declaration

method_declaration: "public" type "identifier" "(" formals ")" "{" statement_list "}"
				  | "public" type "identifier" "(" ")" "{" statement_list "}"

variable_declaration: type "identifier" ";"

formals: type "identifier"
	  |  formals "," type "identifier"

type: simple_type 
	| simple_type "[]"

simple_type: "int"
		   | "boolean" 
		   | "void" 
		   | "identifier"

statement_list: statement_list statement
				| %empty

statement: "assert" "(" expr ")" ";" 
    	 | variable_declaration 
         | "{" statement_list "}"  
         | "if"  "(" expr ")" statement   
         | "if"  "(" expr ")" statement "else" statement 
         | "while"  "(" expr ")" statement  
         | "System" "." "out" "." "println" "(" expr ")" ";"  
         | "lvalue" "=" expr ";" 
         | "return" expr ";"  
         | method_invocation ";"

method_invocation: call_expr "." "identifier" "(" expr_list ")"
				 | call_expr "." "identifier" "(" ")"

call_expr: "this" 
		  | method_invocation 
		  | "new" simple_type "[" expr "]"  
    	  | "new" simple_type "(" ")" 
		  | lvalue

expr_list: expr
		  | expr_list "," expr 

lvalue: "identifier" 
	   | "identifier" "[" expr "]" 

expr: expr "&&" expr  
	| expr "||" expr
	| expr "<" expr
	| expr ">" expr
	| expr ">=" expr
	| expr "!=" expr
	| expr "<=" expr
	| expr "==" expr   
	| expr "+" expr     
	| expr "-" expr    
	| expr "*" expr  
	| expr "/" expr  
	| expr "%" expr  
	| call_expr "." "length"   
	| call_expr
	| "!" expr 
    | "(" expr ")"   
	| "int"   
	| "true"  
	| "false"     

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
