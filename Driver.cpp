#include "Driver.hpp"
#include <sstream>

Driver::Driver(){
    dir = 0;
    numEtiquetas = 0;
    numTemporales = 0;
    cteFloat = 0;
}

Driver::~Driver(){
}

// Funciones para tabla de tipos
int agregar_tipo(string nombre, int tam_bytes, SymTab *tipo_base);
//
void agregar_simbolo(std::string id, int tipo, std::string categoria);
void agregar_simbolo(std::string id, int tipo, std::vector<int> args);

string nuevaEtiqueta(){
    stringstream etiqueta;
    label << "L" << numEtiquetas++;
    return etiqueta.str();
}

string nuevaTemporal(){
    stringstream temporal;
    temp << "t" << numTemporales++;
    return temporal.str();
}

Expresion Driver::disyuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "||";
        codigo_intermedio.push_back(c);
    }
    else {
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

Expresion Driver::conjuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo)){
        Cuadrupla c;
        c.arg1 = e1.dir;
        c.arg2 = e2.dir;
        c.resultado = e.dir;
        c.operador = "&&";
        codigo_intermedio.push_back(c);
    }else{
        error_semantico("Los tipos de los operandos son incompatibles");
    }
}

bool Driver::compatibles(int t1, int t2){
    std::string nombre = tt.getNombre(t1);
    std::string nombre2 = tt.getNombre(t2);
    if(nombre =="struct" && nombre2=="struct"){
        //Validar la equivalencia de los campos de los tipos
        //estructurados
    }
    if(t1==t2) return true;
    if(t1 ==1 || t2 == 2) return true;
    return false;  
}

Expresion Driver::numero(std::string val, int tipo){
    if( tipo == 2){
        stringstream cte;
        cte<<"cteFloat"<<cteFloat++;
        Numero num;
        num.val = val;
        num.tipo = tipo;
        contantes[cte.str()] = num;
    }
}

void Driver::gen_goto(string label){
    Cuadrupla c;
    c.operador = "goto";
    c.arg1 = "";
    c.arg2 = "";
    c.resultado = label;
    codigo_intermedio.push_back(c);   
}

void Driver::gen_if(string var, string ltrue){
    Cuadrupla c;
    c.operador = "if";
    c.arg1 = var;
    c.arg2 = "goto";
    c.resultado = ltrue;
    codigo_intermedio.push_back(c);
}

void Driver::gen_label(string label){
    Cuadrupla c;
    c.operador = "label";
    c.arg1 = "";
    c.arg2 = "";
    c.resultado = label;
    codigo_intermedio.push_back(c);
}

std::string Driver::ampliar(std::string dir, int t1, int t2){
    string temp;
    Cuadrupla c;
    if(t1 == t2)
        return dir;
    else if(t1 == 0 && t2 == 1){
        temp = nuevaTemporal();
        c.operador = "(float)";
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        codigo_intermedio.push_back(c);
        //addSym(temp,1,"temporal");
        return temp;
    }
    else
        return "";
}

std::string Driver::reducir(std::string dir, int t1, int t2){
    string temp;
    Cuadrupla c;
    if(t1 == t2) 
        return dir;
    else if(t1 == 1 && t2 == 0){
        temp = nuevaTemporal();
        c.operador = "(int)";
        c.arg1 = dir;
        c.arg2 = "";
        c.resultado = temp;
        codigo_intermedio.push_back(c);
        //addSym(temp, 0, "temporal");        
        return temp;
    }
    else 
        return "";
}

int Driver::maximo(int t1, int t2){
    if(t1 == t2) return t1;
    else if(t1 == 0 && t2 == 1) return 1;
    else if(t1 == 1 && t2 == 0) return 1;
    else return -1;
}

int Driver::minimo(int t1, int t2){
    if(t1==t2) return t1;
    else if(t1==0 && t2==1) return 0;
    else if(t1==1 && t2==0) return 0;
    else return -1;
}

void Driver::error_semantico(std::string mensaje){
    cout << "Error semántico " << mensaje << endl;
    exit(EXIT_FAILURE);
}

void Driver::gen_imprimir(string val){
    for(vector<Cuadrupla>::iterator q = codigo_intermedio.begin(); q != codigo_intermedio.end(); q++)
    {
        q->print();
    }
    cout<<endl;
}

void Driver::asignacion(std::string id, Expresion e){
}

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

void Driver::gen_lectura(string dir){
}