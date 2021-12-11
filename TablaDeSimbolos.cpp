#include "TablaDeSimbolos.hpp"

TablaDeSimbolos::TablaDeSimbolos(){
}

TablaDeSimbolos::~TablaDeSimbolos(){
}

/*
 * Agrega un símbolo a la tabla de símbolos
 */
void TablaDeSimbolos::addSim(string id, Sim s){
    simbolos[id] = s;
}

/*******************************************************************************/
/*    Funciones para acceder a la información en la tabla de símbolos **********/
/*******************************************************************************/

int TablaDeSimbolos::getDireccion(string id){
    return simbolos[id].getDireccion();
}

int TablaDeSimbolos::getTipo(string id){
    return simbolos[id].getTipo();
}

string TablaDeSimbolos::getCat(string id){
    return simbolos[id].getCat();
}

vector<int> TablaDeSimbolos::getArgumentos(string id){
    return simbolos[id].getArgumentos();
}

bool TablaDeSimbolos::is_in(string id){
    map<string,Sym>::iterator it;
    it = simbolos.find(id);
    return it != simbolos.end();
}

map<string,Sym> TablaDeSimbolos::getSims(){
    return simbolos;
}