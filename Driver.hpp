#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include <vector>
#include <string>
using namespace std;

#include "TypeTab.hpp"
#include "SymTab.hpp"
#include "Quad.hpp"
#include "SymbolTypes.hpp"
#include "Generator.hpp"
#include "Pila.hpp"
#include "Lexer.hpp"
#include "parser.tab.hh"

class Driver{
private:
    int dir;
    int numTemp;
    int numLabel;
    int numType;
    int gType;
    int cteF;
    SymTab ts;  //Tabla de símbolos globales
    TypeTab tt; //Tabla de tipos
    vector<Quad> icode; //Código intermedio
    map<string, string> constantes;
    map<string, int> labelStruct;
    map<string, Expresion> lreturn;
    Generator gen;
    Pila<SymTab> symTabStack;   //Pila de tablas de símbolos
    Pila<int> labelStack;
    Lexer *lexer = nullptr;
    yy::Parser *parser = nullptr;

public:
    Driver(/* args */);
    Driver(string file);
    ~Driver();

    void setFile(string file);
    void setType(int type);
    int getType();

    void pushLabel(int label);
    void popLabel();
    int topLabel();
    int element(int i);
    // Funciones para generar código intermedio    
    string newLabel();
    string newLabel(int num);
    int newLab();
    string newTemp();
    void genCode(string res, string arg1, string op, string arg2);
    void _label(string label);
    void _goto(string label);
    void _if(string var, string label);
    string ampliar(string dir, int t1, int t2);
    string reducir(string dir, int t1, int t2);
    int max(int t1, int t2);    
    int min(int t1, int t2);

    //Funciones de análisis semántico
    void addSym(string id, int type, string cat);
    void addSym(string id, int dir, int type, string cat);
    void addSym(string id, int type, string cat, vector<int> args);
    int addType(string name, int items, int base);
    int addType(int type, string name, SymTab *tab);
    int addType(string name, SymTab *tab);

    //
    Expresion mas(Expresion e1, Expresion e2);
    Expresion menos(Expresion e1, Expresion e2);
    Expresion mul(Expresion e1, Expresion e2);
    Expresion div(Expresion e1, Expresion e2);
    Expresion asig(string id, Expresion e);
    Expresion ident(string id);
    Expresion numero(string val, int type);
    Expresion caracter(string val, int type);
    void error(string msg);
    void print();
    void translate();
    SymTab symtab();
    void pushSymT(SymTab ts);
    SymTab popSymT();
    Expresion _return(string id, Expresion e);
    Expresion retorno(string id, vector<int> params);
    void estructura(string id);
    Expresion retStruct(string ids, string ida);

    Expresion mayor_que(Expresion e1, Expresion e2);
    Expresion menor_que(Expresion e1, Expresion e2);
    Expresion mayor_o_igual(Expresion e1, Expresion e2);
    Expresion menor_o_igual(Expresion e1, Expresion e2);
    Expresion disyuncion(Expresion e1, Expresion e2);
    Expresion conjuncion(Expresion e1, Expresion e2);
    Expresion igual(Expresion e1, Expresion e2);
    Expresion distinto(Expresion e1, Expresion e2);
    Expresion negacion(string id, Expresion e);
    Expresion imprimir(Expresion e);
    Expresion ler(string id);
    int expType(Expresion e);

    void parse(const string& file);
    void parse_helper(std::istream &stream);
};




#endif // !__DRIVER_HPP__
