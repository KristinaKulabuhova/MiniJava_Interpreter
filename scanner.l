%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
    #include "Visitors/Visitor.h"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
str   "'"[^'\n]*"'"
int   [0-9]*
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();


  //"'"        return yy::parser::make_QUOTE    (loc);
%}

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"-"        {
              std::cout << loc.begin.line << " " << loc.end.line << std::endl;
              return yy::parser::make_MINUS  (loc);
           }

"program"  return yy::parser::make_PROGRAM  (loc);

"begin"    return yy::parser::make_BEGIN   (loc);
"end"      return yy::parser::make_END   (loc);
"var"      return yy::parser::make_VAR   (loc);
"if"       return yy::parser::make_IF   (loc);
"then"     return yy::parser::make_THEN   (loc);
"else"     return yy::parser::make_ELSE   (loc);
"while"    return yy::parser::make_WHILE   (loc);
"do"       return yy::parser::make_DO   (loc);
"not"      return yy::parser::make_NOT   (loc);
"to"       return yy::parser::make_TO   (loc);
"for"      return yy::parser::make_FOR  (loc);



","        return yy::parser::make_COMMA   (loc);
";"        return yy::parser::make_SEMICOLON   (loc);
"."        return yy::parser::make_DOT   (loc);
":"        return yy::parser::make_COLON   (loc);

"read"     return yy::parser::make_READ   (loc);
"write"     return yy::parser::make_WRITE   (loc);

"+"        return yy::parser::make_PLUS   (loc);
"*"        return yy::parser::make_STAR   (loc);
"div"      return yy::parser::make_DIV  (loc);
"mod"      return yy::parser::make_MOD  (loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
":="       return yy::parser::make_ASSIGN (loc);
"or"       return yy::parser::make_OR (loc);
"and"      return yy::parser::make_AND (loc);

"<"        return yy::parser::make_L   (loc);
"<="       return yy::parser::make_LEQ   (loc);
"="        return yy::parser::make_EQ   (loc);
"<>"       return yy::parser::make_NEQ   (loc);
">"        return yy::parser::make_G   (loc);
">="       return yy::parser::make_GEQ   (loc);

{str}      return yy::parser::make_STR (yytext, loc);
{int}      return yy::parser::make_INT (yytext, loc);
{id}       return yy::parser::make_IDENTIFIER(yytext, loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_FILEEND (loc);
%%