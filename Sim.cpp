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
Sim::Sim(int direccion, int tipo, string cat, vector<int> argumentos){
    this->direccion = direccion;
    this->tipo = tipo;
    this->cat = cat;
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