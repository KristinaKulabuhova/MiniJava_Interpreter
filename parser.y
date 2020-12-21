%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <vector>
    class Scanner;
    class Driver;

    class VarDeclList;
    class BaseExecBlock;
    class ExecCode;
    class Assignment;
    class For;
    class If;
    class Read;
    class Write;
    class While;

    class BaseExpr;
    class AddExpr;
    class DivExpr;
    class ModExpr;
    class MulExpr;
    class SubtractExpr;
    class IdentExpr;
    class ConstExpr;
    class LessExpr;
    class GreaterExpr;
    class LeqExpr;
    class GeqExpr;
    class EqExpr;
    class NEqExpr;
    class AndExpr;
    class OrExpr;
    class NotExpr;

    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "VarDeclList/VarDeclList.h"
    #include "MainElements/ExecCode.h"
    #include "MainElements/Assignment.h"
    #include "MainElements/For.h"
    #include "MainElements/If.h"
    #include "MainElements/Read.h"
    #include "MainElements/Write.h"
    #include "MainElements/While.h"

    #include "Expressions/AddExpr.h"
    #include "Expressions/DivExpr.h"
    #include "Expressions/IdentExpr.h"
    #include "Expressions/ModExpr.h"
    #include "Expressions/MulExpr.h"
    #include "Expressions/SubtractExpr.h"
    #include "Expressions/ConstExpr.h"

    #include "Expressions/LessExpr.h"
    #include "Expressions/GreaterExpr.h"
    #include "Expressions/LeqExpr.h"
    #include "Expressions/GeqExpr.h"
    #include "Expressions/EqExpr.h"
    #include "Expressions/NEqExpr.h"
    #include "Expressions/AndExpr.h"
    #include "Expressions/OrExpr.h"
    #include "Expressions/NotExpr.h"

    #include "Program.h"

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
    PROGRAM "program"
    ASSIGN ":="
    MINUS "-"
    PLUS "+"
    STAR "*"
    LPAREN "("
    RPAREN ")"
    BEGIN "begin"
    END "rend"
    COMMA ","
    SEMICOLON ";"
    DOT "."
    COLON ":"
    VAR "var"
    IF "if"
    THEN "then"
    ELSE "else"
    WHILE "while"
    FOR "for"
    DO "do"
    NOT "not"
    TO "to"
    READ "read"
    WRITE "write"
    DIV "div"
    MOD "mod"
    OR "or"
    AND "and"
    L "<"
    LEQ "<="
    EQ "="
    NEQ "<>"
    G ">"
    GEQ ">="
;

%token <std::string> IDENTIFIER "identifier"
%token <std::string> INT "int"
%token <std::string> STR "str"
%nterm <std::vector<VarDeclList*>> var_declarations
%nterm <VarDeclList*> var_decl_list
%nterm <ExecCode*> exec_code
%nterm <BaseExecBlock*> exec_block
%nterm <Assignment*> assignment
%nterm <For*> for
%nterm <If*> if
%nterm <ExecCode*> line_or_code
%nterm <Read*> read
%nterm <Write*> write
%nterm <While*> while
%nterm <BaseExpr*> expr
%nterm <Program*> program

//%printer { yyo << $$; } <*>;

%%

%left "+" "-";
%left "*" "div" "mod";

%start unit;
unit: program { driver.program = $1; };

program: "program" "identifier" ";" "var" var_declarations "begin" exec_code "rend" "." { $$ = new Program($2, $5, $7); }
	| "program" "identifier" ";" "begin" exec_code "rend" "." { $$ = new Program($2, {}, $5); };

var_declarations: var_decl_list {
		std::vector<VarDeclList*> declarations;
		declarations.push_back($1);
		$$ = declarations;
	}
	| var_decl_list var_declarations {
		$2.push_back($1);
		$$ = $2;
	}

var_decl_list: "identifier" ":" "identifier" ";" {
		$$ = new VarDeclList($1, $3);
	}
	| "identifier" "," var_decl_list {
		$3->addVar($1);
		$$ = $3;
	};

exec_code: exec_block {
		$$ = new ExecCode($1);
	}
	| exec_code exec_block {
		$1->addBaseBlock($2);
		$$ = $1;
	};

exec_block: assignment {
		$$ = $1;
	}
	| for {
		$$ = $1;
	}
	| if {
		$$ = $1;
	}
	| read {
		$$ = $1;
	}
	| while {
		$$ = $1;
	}
	| write {
		$$ = $1;
	};

assignment: "identifier" ":=" expr ";" {
		$$ = new Assignment($1, $3);
	};

for: "for" "identifier" ":=" expr "to" expr "do" line_or_code ";" {
		$$ = new For($2, $4, $6, $8);
	}

if: "if" expr "then" line_or_code ";" {
		$$ = new If($2, $4, nullptr);
	}
	| "if" expr "then" line_or_code ";" "else" line_or_code ";" {
		$$ = new If($2, $4, $7);
	};

line_or_code: exec_block {
		$$ = new ExecCode($1);
	}
	| "begin" exec_code "rend" {
		$$ = $2;
	};

read: "read" "(" "identifier" ")" ";" {
		$$ = new Read($3);
	};

while: "while" expr "do" line_or_code ";" {
		$$ = new While($2, $4);
	};

write: "write" "(" expr ")" ";"	{
		$$ = new Write($3);
	};

expr: expr "+" expr {
		$$ = new AddExpr($1, $3);
	}
	| expr "and" expr {
		$$ = new AndExpr($1, $3);
	}
	| "int" {
		$$ = new ConstExpr($1);
	}
	| "str" {
		$$ = new ConstExpr($1);
	}
	| expr "div" expr {
		$$ = new DivExpr($1, $3);
	}
	| expr "=" expr {
		$$ = new EqExpr($1, $3);
	}
	| expr ">=" expr {
		$$ = new GeqExpr($1, $3);
	}
	| expr ">" expr {
		$$ = new GreaterExpr($1, $3);
	}
	| "identifier" {
		$$ = new IdentExpr($1);
	}
	| expr "<=" expr {
		$$ = new LeqExpr($1, $3);
	}
	| expr "<" expr {
		$$ = new LessExpr($1, $3);
	}
	| expr "mod" expr {
		$$ = new ModExpr($1, $3);
	}
	| expr "*" expr {
		$$ = new MulExpr($1, $3);
	}
	| expr "<>" expr {
		$$ = new NEqExpr($1, $3);
	}
	| "not" expr {
		$$ = new NotExpr($2);
	}
	| expr "or" expr {
		$$ = new OrExpr($1, $3);
	}
	| expr "-" expr {
		$$ = new SubtractExpr($1, $3);
	}
	| "(" expr ")" {
		$$ = $2;
	};

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
