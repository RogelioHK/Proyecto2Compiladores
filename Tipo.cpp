#include "Tipo.hpp"

Tipo::Tipo(){}

Tipo::~Tipo(){}

/*
 * Crea un tipo a partir de su nombre y tamaño
 * sirve para los tipos nativos
 * @param nombre nombre del tipo
 * @param tam tamaño del tipo nativo
 */
Tipo::Tipo(string nombre, int tam){
    this->nombre = nombre;
    this->isTable = false;
    this->base.base = -1;
    this->items= -1;
    this->tam = tam;
}

/*
 * Crea un tipo para las estructuras
 * @param nombre nombre del tipo (struct)
 * @param tab tabla de símbolos para la estructura
 * @param tam tamaño en bytes de la tabla de símbolos
 */
Tipo::Tipo(string nombre, TablaDeSimbolos *tab, int tam)
{
    this->nombre = nombre;
    this->isTable = true;
    this->base.tab = tab;
    this->items = -1;
    this->tam = tam;
}

/*
 * Crea un tipo para los arreglos
 * @param nombre nombre del tipo (array)
 * @param items número de elementos del arreglo
 * @param tam tamaño en bytes
 */
Tipo::Tipo(string nombre, int items, int base, int tam)
{
    this->nombre = nombre;
    this->isTable = false;
    this->base.base = base;
    this->items = items;
    this->tam = tam;
}

int Tipo::getTam(){
    return tam;
}

TablaDeSimbolos *Tipo::getTab(){
    if(isTable) 
        return base.tab;
    return nullptr;
}   

int Tipo::getItems(){
    return items;
}

int Tipo::getBase(){
    if(!isTable) return 
        base.base;
    return -1;
}

string Tipo::getNombre(){
    return  nombre;
}