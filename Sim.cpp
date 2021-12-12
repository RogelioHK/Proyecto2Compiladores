#include "Sim.hpp"

Sim::Sim(){}

/*
 * Crea un símbolo para una variable
 */
Sim::Sim(int direccion, int tipo, string cat){
    this->direccion = direccion;
    this->tipo = tipo;
    this->cat = cat;
}

/*
 * Crea un símbolo para una función
 */
//Falta cat en los argumentos
Sim::Sim(int direccion, int tipo, vector<int> argumentos){
    this->direccion = direccion;
    this->tipo = tipo;
    //this->cat = cat;
    this->argumentos = argumentos;
}

Sim::~Sim(){}

int Sim::getDireccion(){
    return direccion;
}

int Sim::getTipo(){
    return tipo;
}

string Sim::getCat(){
    return cat;
}

vector<int> Sim::getArgumentos(){
    return argumentos;
}