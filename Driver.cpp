#include "Driver.hpp"
#include <iostream>
#include <sstream>

Driver::Driver(){
    dir = 0;
    numEtiquetas = 0;
    numTemporales = 0;
    numTipos = 0;
    cteFloat = 0;
}

Driver::~Driver(){
}

// Funciones para tabla de tipos
int Driver::agregar_tipo(string nombre, int tam_bytes, TablaDeSimbolos *tipo_base){
    tt.addTipo(tam_bytes, nombre, tipo_base);
    return numTipos-1;
}
//

void Driver::agregar_simbolo(std::string id, int tipo, std::string categoria){
    agregar_simbolo(id, dir, tipo, categoria);
    dir += tt.getTam(tipo);
}

void Driver::agregar_simbolo(string id, int dir, int tipo, string categoria){
    if(!ts.is_in(id))
        ts.addSim(id, Sim(dir,tipo, categoria));
    else
        error_semantico("La variable " + id + " ya fue declarada.");
}

//Falta cat en los argumentos
void Driver::agregar_simbolo(std::string id, int tipo, std::vector<int> args){
    ts.addSim(id,Sim(dir,tipo,args));
}

std::string Driver::nuevaEtiqueta(){
    stringstream etiqueta;
    etiqueta << "L" << numEtiquetas++;
    return etiqueta.str();
}

std::string Driver::nuevaTemporal(){
    stringstream temporal;
    temporal << "t" << numTemporales++;
    return temporal.str();
}

Expresion Driver::disyuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla("||",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::conjuncion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla("&&",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla("==",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::distinto(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla("!=",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::mayor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla(">",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::menor_que(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla("<",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::mayor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla(">=",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
}

Expresion Driver::menor_o_igual(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = 1; // Depende de la tabla de tipos
    e.dir = nuevaTemporal();
    if(compatibles(e1.tipo, e2.tipo))
        codigo_intermedio.push_back(Cuadrupla("<=",e1.dir,e2.dir,e.dir));
    else
        error_semantico("Los tipos de los operandos son incompatibles");
    return e;
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
        constantes[cte.str()] = num;
    }
}

void Driver::gen_goto(string etiqueta){
    codigo_intermedio.push_back(Cuadrupla("goto", "","", etiqueta));
}

void Driver::gen_if(string var, string ltrue){
    codigo_intermedio.push_back(Cuadrupla("if", var, "goto", ltrue));
}

void Driver::gen_label(string etiqueta){
    codigo_intermedio.push_back(Cuadrupla("label", "","", etiqueta));
}

std::string Driver::ampliar(std::string dir, int t1, int t2){
    string temp;
    //Cuadrupla c;
    if(t1 == t2)
        return dir;
    else if(t1 == 0 && t2 == 1){
        temp = nuevaTemporal();
        codigo_intermedio.push_back(Cuadrupla("(float)",dir,"",temp));
        agregar_simbolo(temp,1,"temporal");
        return temp;
    }
    else
        return "";
}

std::string Driver::reducir(std::string dir, int t1, int t2){
    string temp;
    //Cuadrupla c;
    if(t1 == t2) 
        return dir;
    else if(t1 == 1 && t2 == 0){
        temp = nuevaTemporal();
        codigo_intermedio.push_back(Cuadrupla("(int)",dir,"",temp));
        agregar_simbolo(temp, 0, "temporal");        
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
    for(vector<Cuadrupla>::iterator q = codigo_intermedio.begin(); q != codigo_intermedio.end(); q++){
        q -> imprimir();
    }
    cout<<endl;
}

Expresion Driver::identificador(std::string id){
    Expresion e;
    if(ts.is_in(id)){
        e.dir = id;
        e.tipo = ts.getTipo(id);
    }
    else{
        error_semantico("El identificador " + id + " no fue declarado.");
    }
}

Expresion Driver::asignacion(std::string id, Expresion e){
    Expresion e1;
    string alfa;
    int tipoId;

    if(!ts.is_in(id))
        error_semantico("La variable " + id + " no fue declarada.");
    
    tipoId = ts.getTipo(id);
    e1.tipo = tipoId;

    if(tipoId == e.tipo){
        alfa = e.dir;
    }
    else if(tipoId > e.tipo){
        alfa = ampliar(e.dir, e.tipo, e1.tipo);
    }
    else if(minimo(tipoId, e.tipo) != 1){
        alfa = reducir(e.dir, e.tipo, e1.tipo);
    }
    else{
        error_semantico("Los tipos son incompatibles.");
    }
    codigo_intermedio.push_back(Cuadrupla("=",alfa,"",id));
    return e1;
}

Expresion Driver::suma(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo, e2.tipo);

    if(e.tipo != -1){
        e.dir = nuevaTemporal();
        agregar_simbolo(e.dir,e.tipo,"temporal");
        string alfa1 = ampliar(e1.dir, e1.tipo, e.tipo);
        string alfa2 = ampliar(e2.dir, e2.tipo, e.tipo);
        codigo_intermedio.push_back(Cuadrupla("+",alfa1,alfa2,e.dir));
    }
    else{
        error_semantico("Los tipos son incompatibles.");
    }
    return e;
}

Expresion Driver::resta(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo, e2.tipo);
    
    if(e.tipo != -1){
        string alfa1 = ampliar(e1.dir, e1.tipo, e.tipo);
        string alfa2 = ampliar(e2.dir, e2.tipo, e.tipo);
        codigo_intermedio.push_back(Cuadrupla("-",alfa1,alfa2,e.dir));
    }
    else{
        error_semantico("Los tipos son incompatibles.");
    }
    return e;
}

Expresion Driver::multiplicacion(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo, e2.tipo);
    if(e.tipo!=-1){
        string alfa1 = ampliar(e1.dir, e1.tipo, e.tipo);
        string alfa2 = ampliar(e2.dir, e2.tipo, e.tipo);
        codigo_intermedio.push_back(Cuadrupla("*",alfa1,alfa2,e.dir));
    }else{
        error_semantico("Los tipos son incompatibles.");
    }
    return e;
}
Expresion Driver::division(Expresion e1, Expresion e2){
    Expresion e;
    e.tipo = maximo(e1.tipo, e2.tipo);
    if(e.tipo!=-1){
        string alfa1 = ampliar(e1.dir, e1.tipo, e.tipo);
        string alfa2 = ampliar(e2.dir, e2.tipo, e.tipo);
        codigo_intermedio.push_back(Cuadrupla("/",alfa1,alfa2,e.dir));
    }else{
        error_semantico("Los tipos son incompatibles.");
    }
    return e;
}
 
Expresion Driver::negacion(Expresion e1){

}

//exp2.dir = nuevaTemporal()
//exp2.type = exp3.type()
//genCode(exp2.dir, “!”, expres.dir)


void Driver::gen_lectura(string dir){
}