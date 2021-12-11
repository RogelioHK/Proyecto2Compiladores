#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__
#include <string>
#include <map>
#include <stack>
#include <vector>
using namespace std;

#include "TablaDeSimbolos.hpp"

struct Cuadrupla{
    std::string arg1;
    std::string arg2;
    std::string operador;
    std::string resultado;
};

//class SymTab;
struct Expresion{
    std::string dir;
    int tipo;
    Expresion(string dir, int tipo = 0){
        this -> tipo = tipo;
        this -> dir = dir;
    };

    Expresion(int tipo = 0){
        this -> tipo = tipo;
        this -> dir = "";    
    }
};

struct Numero{
    std::string val;
    int tipo;
};

class Driver{
private:
    TipoTab tt;
    //Pila de tablas de símbolos
    std::vector<Cuadrupla> codigo_intermedio;
    TablaDeSimbolos ts;
    std::stack<std::string> pilaEtiques;
    std::stack<int> pilaDir;
    std::stack<int> pilaTemporal;
    std::map<std::string, std::string> tstring;
    std::map<std::string, Numero> constantes;
    int retorno;
    bool tieneRetorno;
    int dir;
    int numEtiquetas;
    int numTemporales;
    int numTipos;
    int cteFloat;
    
    //Generador de codigo final

public:
    Driver();
    ~Driver();
    // Funciones para tabla de tipos
    int agregar_tipo(string nombre, int tam_bytes, TablaDeSimbolos *tipo_base);
    //
    void agregar_simbolo(std::string id, int tipo, std::string categoria);
    void agregar_simbolo(std::string id, int tipo, std::vector<int> args);

    string nuevaEtiqueta();
    string nuevaTemporal();
    

    Expresion asignacion(std::string id, Expresion e);
    Expresion disyuncion(Expresion e1, Expresion e2);
    Expresion conjuncion(Expresion e1, Expresion e2);
    Expresion igual(Expresion e1, Expresion e2);
    Expresion distinto(Expresion e1, Expresion e2);
    Expresion mayor_que(Expresion e1, Expresion e2);
    Expresion menor_que(Expresion e1, Expresion e2);
    Expresion mayor_o_igual(Expresion e1, Expresion e2);
    Expresion menor_o_igual(Expresion e1, Expresion e2);
    Expresion suma(Expresion e1, Expresion e2);
    Expresion resta(Expresion e1, Expresion e2);
    Expresion multiplicacion(Expresion e1, Expresion e2);    
    Expresion division(Expresion e1, Expresion e2);    
    Expresion negacion(Expresion e1);
    Expresion identificador(std::string id);
    Expresion numero(std::string val, int tipo);

    std::string ampliar(std::string dir, int t1, int t2);
    std::string reducir(std::string dir, int t1, int t2);
    int maximo(int t1, int t2);
    int minimo(int t1, int t2);
    bool compatibles(int t1, int t2);

    void error_semantico(std::string mensaje);
    void gen_imprimir(string val);
    void gen_lectura(string dir);
    void gen_label(string label);
    void gen_goto(string label);
    void gen_if(string var, string ltrue);
};

#endif // !__DRIVER_HPP__