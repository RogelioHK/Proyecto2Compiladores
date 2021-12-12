#include "TipoTab.hpp"

TipoTab::TipoTab(){}

TipoTab::~TipoTab(){}

/*
 * Función para agregar un tipo nativo en la tabla de tipos
 */
void TipoTab::addTipo(int id, string nombre, int tam){
    tipos[id] = Tipo(nombre, tam);
}

/*
 * Función para agregar un tipo de array en la tabla de tipos
 */
void TipoTab::addTipo(int id, string nombre, int items,  int base){
    int tam = tipos[base].getTam()*items;
    tipos[id] = Tipo(nombre, items, base, tam);
}

/*
 * Función para agregar un tipo struct en la tabla de tipos
 */
void TipoTab::addTipo(int id, string nombre, TablaDeSimbolos *tab){
    int tam = 100;
    tipos[id] = Tipo(nombre, tab, tam);
}

/****************************************************************************************/
/* Funciones para devolver las características de un tipo de acuerdo a su identificador */
/****************************************************************************************/

int TipoTab::getTam(int id){
    return tipos[id].getTam();
}

int TipoTab::getItems(int id){
    return tipos[id].getItems();
}

TablaDeSimbolos *TipoTab::getTab(int id){
    return tipos[id].getTab();
}

int TipoTab::getBase(int id){
    return tipos[id].getBase();
}

string TipoTab::getNombre(int id){
    return tipos[id].getNombre();
}