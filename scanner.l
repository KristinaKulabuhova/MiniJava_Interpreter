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
str   \"[^"\n]*["\n]
num   [0-9]*
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


  //"'"        return yy::parser::make_QUOTE      (loc);
%}

{blank}+    loc.step ();
\n+         loc.lines (yyleng); loc.step ();

"class"     return yy::parser::make_CLASS         (loc);
"public"    return yy::parser::make_PUBLIC        (loc);
"static"    return yy::parser::make_STATIC        (loc);
"extends"   return yy::parser::make_EXTENDS       (loc); 

"false"     return yy::parser::make_FALSE         (loc);
"true"      return yy::parser::make_TRUE          (loc);
"new"       return yy::parser::make_NEW           (loc);
"out"       return yy::parser::make_OUT           (loc);
"main"      return yy::parser::make_MAIN          (loc);
"assert"    return yy::parser::make_ASSERT        (loc);
"this"      return yy::parser::make_THIS          (loc);
"println"   return yy::parser::make_PRINTLN       (loc);
"System"    return yy::parser::make_SYSTEM        (loc);
"length"    return yy::parser::make_LENGTH        (loc);

"void"      return yy::parser::make_VOID          (loc);
"int"       return yy::parser::make_INT           (loc);
"boolean"   return yy::parser::make_BOOL          (loc);
"return"    return yy::parser::make_RETURN        (loc);

"("         return yy::parser::make_LROUND        (loc); 
")"         return yy::parser::make_RROUND        (loc);
"{"         return yy::parser::make_LCURLY        (loc);
"}"         return yy::parser::make_RCURLY        (loc);
"["         return yy::parser::make_LSQUARE       (loc);
"]"         return yy::parser::make_RSQUARE       (loc);
"[]"        return yy::parser::make_BRACKS        (loc);

"while"     return yy::parser::make_WHILE         (loc);
"if"        return yy::parser::make_IF            (loc);
"else"      return yy::parser::make_ELSE          (loc);

","         return yy::parser::make_COMMA         (loc); 
";"         return yy::parser::make_SEMICOLON     (loc);
"."         return yy::parser::make_DOT           (loc);

"&&"        return yy::parser::make_AND           (loc); 
"||"        return yy::parser::make_OR            (loc);
"=="        return yy::parser::make_EQ            (loc);
"!="        return yy::parser::make_NEQ           (loc);
"!"         return yy::parser::make_NEG           (loc);
">="        return yy::parser::make_GEQ           (loc);
"<="        return yy::parser::make_LEQ           (loc);
">"         return yy::parser::make_GREATER       (loc);
"<"         return yy::parser::make_LESS          (loc);
"="         return yy::parser::make_ASSIGN        (loc); 

"+"         return yy::parser::make_PLUS          (loc);
"-"         return yy::parser::make_MINUS         (loc);  
"/"         return yy::parser::make_SLASH         (loc);
"%"         return yy::parser::make_MODUL         (loc);
"*"         return yy::parser::make_STAR          (loc);  

{str}       return yy::parser::make_STR       (yytext, loc);
{num}       return yy::parser::make_NUM       (yytext, loc);
{id}        return yy::parser::make_IDENTIFIER(yytext, loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_FILEEND (loc);
%%
