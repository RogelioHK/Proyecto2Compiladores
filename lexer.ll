%{
#include <iostream>
#include <string>
using namespace std;

#include "Lexer.hpp"

#undef YY_DECL
#define YY_DECL int Lexer::yylex(yy::Parser::semantic_type *const lval, yy::Parser::location_type *location)
using token = yy::Parser::token;

#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

int line=1;
int numType;

%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"

caracter ["][a-zA-Z0-9_]["]
id [a-zA-Z_][a-zA-Z0-9_]*
ent [0-9]+
notacion [eE][+-]?[0-9]+
real ([0-9]+"."[0-9]*"."[0-9]+){notacion}?|[0-9]+{notacion}
doble ([0-9]+"."[0-9]*|"."[0-9]+){notacion}?|[0-9]*{notacion}

%%
%{  /** Code executed at the beginning of yylex **/
    yylval = lval;
%}
"=" { return token::ASIG; }
"+" { return token::MAS; }
"*" { return token::MUL; }
"-" { return token::MENOS; }
"/" { return token::DIV; }
"(" { return token::LPAR; }
")" { return token::RPAR; }
"{" { return token::LKEY; }
"}" { return token::RKEY; }
"," { return token::COMA; }
";" { return token::PYC; }
">" { return token::MAYORQUE; }
"<" { return token::MENORQUE; }
">=" { return token::MAYORIGUAL; }
"<=" { return token::MENORIGUAL; }
"==" { return token::IGUAL; }
"!=" { return token::DIFF; }
"&&" { return token::AND; }
"||" { return token::OR; }
"!"  { return token::NOT; }
"."  { return token::PUNTO; }

"if"     { return token::IF; }
"else"   { return token::ELSE; }
"while"  { return token::WHILE; }
"do"     { return token::DO; }

"int"       { return token::INT; }
"float"     { return token::FLOAT; }
"double"    { return token::DOUBLE; }
"char"      { return token::CHAR; }
"print"     { return token::PRINT; }
"scan"      { return token::SCAN; }
"void"      { return token::VOID; }
"return"    { return token::RETURN; }
"break"     { return token::BREAK; }
"struct"    { return token::STRUCT; }


{caracter}    { 
            numType = 3;
            yylval->build<std::string>(yytext);
            return token::CARACTER; 
        }
{id}    { 
            yylval->build<std::string>(yytext);
            return token::ID; 
        }

{ent}   { 
            numType = 0;
            yylval->build<std::string>(yytext);
            return token::NUMERO;
        }
{real}   { 
            numType = 1;
            yylval->build<std::string>(yytext);
            return token::NUMERO;
        }
{doble}   { 
            numType = 2;
            yylval->build<std::string>(yytext);
            return token::NUMERO;
        }

[ \t\r]+   {}
"\n"    {line++;}
.   { cout<<"ERROR LEXICO "<<yytext<<endl;}
%%
int yyFlexLexer::yywrap(){
    return 1;
}

int Lexer::getLine()
{
    return line;
}


int Lexer::getType()
{
    return numType;
}

string Lexer::getVal(){
    return yytext;
}