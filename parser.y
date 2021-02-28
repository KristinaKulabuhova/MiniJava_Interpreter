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

program: main_class class_declaration_list {$$ = new Program($1, $2);}

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statement "}" "}" { $$ = new MainClass($2, $11); };

class_declaration_list: class_declaration_list class_declaration {$$ = $1; $$->AddDecl($2);}
					  | %empty {$$ = new ClassDeclarationList();}

class_declaration: "class" "identifier" "extends" "identifier" "{" declaration_list "}" ...
				 | "class" "identifier" "{" declaration_list "}" ...

declaration_list: declaration_list declaration {$$ = $1; $$->AddDecl($2);}
				| %empty {$$ = new DeclarationList();}

declaration: variable_declaration {$$ = $1;}
		   | method_declaration {$$ = $1;}

method_declaration: "public" type "identifier" "(" formals ")" "{" statement_list "}"
				  | "public" type "identifier" "(" ")" "{" statement_list "}"

variable_declaration: type "identifier" ";"

formals: type "identifier"
	  |  formals "," type "identifier"

type: simple_type {$$ = $1;}
	| simple_type "[]" ...

simple_type: "int" {$$ = new SimpleType("int");}
		   | "boolean" {$$ = new SimpleType("boolean");}
		   | "void" {$$ = new SimpleType("void");}
		   | "identifier" {$$ = new SimpleType($1);}

statement_list: statement_list statement
				| %empty

statement: "assert" "(" expr ")" ";" 
    	 | variable_declaration 
         | "{" statement_list "}"  
         | "if"  "(" expr ")" statement   
         | "if"  "(" expr ")" statement "else" statement 
         | "while"  "(" expr ")" statement {} 
         | "System" "." "out" "." "println" "(" expr ")" ";"  
         | "lvalue" "=" expr ";" 
         | "return" expr ";"  {} 
         | method_invocation ";" {$$ = MethodInvocation($1);}

method_invocation: call_expr "." "identifier" "(" expr_list ")"
				 | call_expr "." "identifier" "(" ")"

call_expr: "this" {}
		  | method_invocation 
		  | "new" simple_type "[" expr "]"  
    	  | "new" simple_type "(" ")" 
		  | lvalue		{ $$ = new Lvalue($1); }

expr_list: expr
		  | expr_list "," expr 

lvalue: "identifier" 
	   | "identifier" "[" expr "]" 

expr: expr "&&" expr  			{ $$ = new AndExpr($1, $3); }
	| expr "||" expr			{ $$ = new OrExpr($1, $3); }
	| expr "<" expr				{ $$ = new LessExpr($1, $3); }
	| expr ">" expr				{ $$ = new GreaterExpr($1, $3); }
	| expr ">=" expr			{ $$ = new GeqExpr($1, $3); }
	| expr "!=" expr			{ $$ = new NeqExpr($1, $3); }
	| expr "<=" expr			{ $$ = new LeqExpr($1, $3); }
	| expr "==" expr   			{ $$ = new EqExpr($1, $3); }
	| expr "+" expr    			{ $$ = new AddExpr($1, $3); }
	| expr "-" expr     		{ $$ = new SubtractExpr($1, $3); }
	| expr "*" expr  			{ $$ = new MulExpr($1, $3); }
	| expr "/" expr  			{ $$ = new DivExpr($1, $3); }
	| expr "%" expr  			{ $$ = new ModExpr($1, $3); }
	| call_expr "." "length"    { $$ = new LengthExpr($1); }
	| call_expr					{ $$ = $1; }
	| "!" expr 					{ $$ = new NotExpr($2); }
    | "(" expr ")"   			{ $$ = $2; }
	| "int"   					{ $$ = new AddExpr(); }
	| "true"  					{ $$ = new TrueExpr(); }
	| "false"     				{ $$ = new FalseExpr(); }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
