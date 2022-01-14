
%skeleton "lalr1.cc"
%require  "3.8"
%debug 
%defines 
%define api.parser.class {Parser}

%code requires{
#include "SymbolTypes.hpp"

    class Driver;
    class Lexer;

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { Lexer  &lexer  }
%parse-param { Driver  &driver  }

%code{
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.hpp"
#include "Lexer.hpp"

#undef yylex
#define yylex lexer.yylex
}

%define api.value.type variant
%define parse.assert

%token <std::string>     ID
%token <std::string>     NUMERO CARACTER
%token              IF ELSE WHILE DO
%token              INT FLOAT DOUBLE CHAR VOID RETURN BREAK
%token              LKEY RKEY PYC COMA PUNTO
%token              PRINT SCAN STRUCT

%left               ASIG NOT
%left               MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL IGUAL DIFF AND OR
%left               MAS MENOS
%left               MUL DIV
%nonassoc           LPAR RPAR

%type<int>  tipo arg param
%type <Expresion> expresion
%type <vector<int>> lista_args args lista_params params

%locations

%start programa

%%
programa :
    declaraciones
    {
        driver.print();
        driver.translate();
    }
    ;

declaraciones:
    declaraciones declaracion
    | declaracion
    ;

declaracion:
    STRUCT decl2; 
    |
    VOID
    {
        driver.pushSymT(driver.symtab()); 
    } 
    ID LPAR 
    {
        driver.pushLabel(driver.newLab());// final
        driver._label($3);
    }
    lista_args RPAR LKEY decl_locales bloque_sentencias 
    {
        driver.popSymT();
    }
    RKEY
    {
        driver.addSym($3, 4, "fun", $6);
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel(); 
    }
    |
    tipo {driver.setType($1);} decl1
    ;

decl2:
    LKEY
    {
        driver.pushSymT(driver.symtab());
    } 
    body_struct RKEY ID
    {
        driver.estructura($5);
    }
    PYC
    {
        driver.addSym($5, 5, "struct");   
    }
    |
    ID 
    {
        driver.pushSymT(driver.symtab());
    }
    LKEY body_struct RKEY 
    {
        driver.estructura($1);
    }
    PYC
    {
        driver.addSym($1, 5, "struct");
    }
    ;

body_struct:
    decl_locales
    ;

decl1:
    lista_var PYC
    |
    ID 
    {
        driver.pushLabel(driver.newLab());// final
        driver.pushSymT(driver.symtab());
        driver._label($1);
    }
    LPAR lista_args RPAR LKEY decl_locales bloque_sentencias RETURN expresion PYC RKEY
    {
        
        driver._return($1, $10);
        driver.popSymT();
        driver.addSym($1, 4, "fun", $4);
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
    }
    ;

tipo:
    INT { $$ = 0; }
    |
    FLOAT { $$ = 1; }
    |
    DOUBLE { $$ = 2; }
    |
    CHAR { $$ = 3; }
    ;

lista_var:
    lista_var COMA ID{
        driver.addSym($3, driver.getType(), "variable");
    }
    |
    ID{
        driver.addSym($1, driver.getType(), "variable");
    }
    ;

lista_args:
    args
    {
        $$ = $1;
    }
    |
    {
        $$ = vector<int>();
    }
    ;

args:
    args COMA arg
    {
        $$ = vector<int>();
        $$ = $1;
        $$.push_back($3);
    }
    |
    arg
    {
        $$ = vector<int>();
        $$.push_back($1);
    }
    ;

arg:
    tipo ID
    {
        driver.addSym($2, $1, "param");
        $$ = $1;
    }
    ;

bloque_sentencias:
    sentencias
    |
    ;

decl_locales:
    decl_locales decl_local
    | decl_local
    ;

decl_local:
    tipo {driver.setType($1);} lista_var PYC
    ;

sentencias:
    sentencias sentencia
    | sentencia
    ;

sentencia:
    IF LPAR expresion 
    {
        driver.pushLabel(driver.newLab());// next
        driver.pushLabel(driver.newLab());// label true
        driver.pushLabel(driver.newLab());// label false
        driver._if($3.dir, driver.newLabel(driver.element(1)));        
        driver._goto(driver.newLabel(driver.element(2)));
        driver._label(driver.newLabel(driver.element(1)));
    } 
    RPAR LKEY sentencias
    {
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(2)));
    }
    RKEY ELSE LKEY sentencias RKEY
    {
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
    |
    WHILE
    {
        driver.pushLabel(driver.newLab()); // begin
        driver.pushLabel(driver.newLab()); // true
        driver.pushLabel(driver.newLab()); // false
        driver._label(driver.newLabel(driver.element(2)));
    }
    LPAR expresion
    {
        driver._if($4.dir, driver.newLabel(driver.element(1)));
        driver._goto(driver.newLabel(driver.element(0)));
        driver._label(driver.newLabel(driver.element(1)));        
    }
    RPAR LKEY sentencias RKEY
    {
        driver._goto(driver.newLabel(driver.element(2)));
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
        driver.popLabel();
        driver.popLabel();
    }
    |
    DO
    {
        driver.pushLabel(driver.newLab()); // true
        driver.pushLabel(driver.newLab()); // false
        driver._label(driver.newLabel(driver.element(1)));
    }
    LKEY sentencias RKEY WHILE LPAR expresion
    {
        driver._if($8.dir, driver.newLabel(driver.element(1)));
        driver._goto(driver.newLabel(driver.element(0)));      
    }
    RPAR PYC
    {
        driver._label(driver.newLabel(driver.element(0)));
        driver.popLabel();
        driver.popLabel();
    }
    |
    ID ASIG expresion PYC
    {
        driver.asig($1, $3);
    }
    |
    ID NOT expresion PYC
    {
        driver.negacion($1, $3);
    }
    |
    PRINT LPAR expresion RPAR PYC
    {
        driver.imprimir($3);
    }
    |
    SCAN LPAR ID RPAR PYC 
    {
        driver.ler($3);
    }
    /*|
    RETURN expresion PYC
    {
        driver._return($2);
    }*/
    |
    BREAK PYC{
        
        driver._goto(driver.newLabel(driver.element(0)));
    }
    ;

expresion:
    expresion IGUAL expresion {$$=driver.igual($1, $3);}
    |
    expresion DIFF expresion {$$=driver.distinto($1, $3);}
    |
    expresion AND expresion {$$=driver.conjuncion($1, $3);}
    |
    expresion OR expresion {$$=driver.disyuncion($1, $3);}
    |
    expresion MAYORQUE expresion {$$=driver.mayor_que($1, $3);}
    |
    expresion MENORQUE expresion {$$=driver.menor_que($1, $3);}
    |
    expresion MAYORIGUAL expresion {$$=driver.mayor_o_igual($1, $3);}
    |
    expresion MENORIGUAL expresion {$$=driver.menor_o_igual($1, $3);}
    |
    expresion MAS expresion {$$=driver.mas($1, $3);}
    |
    expresion MENOS expresion{$$=driver.menos($1, $3);}
    | 
    expresion MUL expresion{$$=driver.mul($1, $3);}
    | 
    expresion DIV expresion{$$=driver.div($1, $3);}
    | 
    LPAR expresion RPAR{$$=$2;}
    | 
    NUMERO{$$=driver.numero($1, lexer.getType());}
    |
    CARACTER{$$=driver.caracter($1, lexer.getType());}
    |
    ID{$$=driver.ident($1);}
    |
    ID LPAR lista_params RPAR {$$=driver.retorno($1, $3);}
    |
    ID PUNTO ID {$$ = driver.retStruct($1,$3);}
    ;

lista_params:
    params
    {
        $$ = $1;
    }
    |
    {
        $$ = vector<int>();
    }
    ;

params:
    params COMA param
    {
        $$ = vector<int>();
        $$ = $1;
        $$.push_back($3);
    }
    |
    param
    {
        $$ = vector<int>();
        $$.push_back($1);
    }
    ;

param:
    expresion
    {
        $$ = $1.type;
    }
    ;

%%

void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l <<" whith token "<<lexer.getVal()<< endl;
}