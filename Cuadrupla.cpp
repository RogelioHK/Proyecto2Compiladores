#include "Cuadrupla.hpp"
#include <iostream>
Cuadrupla::Cuadrupla(/* args */)
{
}

Cuadrupla::Cuadrupla(string operador, string arg1, string arg2, string resultado){
    this->operador = operador;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->resultado = resultado;
}

Cuadrupla::~Cuadrupla(){}

TipoCuadrupla Cuadrupla::resolverCuad(){
    if(operador == "+") return QMAS;
    if(operador == "-") return QMENOS;
    if(operador == "*") return QMUL;
    if(operador == "/") return QDIV;
    if(operador == "=") return QCOPY;
    if(operador == "if") return QIF;
    if(operador == "goto") return QGOTO;
    if(operador == "label") return QLABEL;
    if(operador=="(float)") return QCASTFLOAT;
    if(operador=="(int)") return QCASTINT;
    return QSIN;
}

void Cuadrupla::imprimir(){
    switch(resolverCuad()){
        case QMAS: 
        case QMENOS:
        case QMUL:
        case QDIV:
            cout<<resultado<<"="<<arg1<<operador<<arg2<<endl;
            break;
        case QIF:
            cout<<operador<<" "<<arg1<<" goto "<<resultado<<endl;
            break;
        case QGOTO:
            cout<<operador<<" "<<resultado<<endl;
            break;
        case QCOPY:
            cout<<resultado<<operador<<arg1<<endl;
            break;
        case QLABEL:
            cout<<resultado<<":";
            break;
        case QCASTFLOAT:
        case QCASTINT:
            cout<<resultado<<"="<<operador<<arg1<<endl;
            break;
        default:
            break;
    }
}


string Cuadrupla::getRes()
{
    return resultado;
}

string Cuadrupla::getArg1()
{
    return arg1;
}

string Cuadrupla::getArg2()
{
    return arg2;
}

string Cuadrupla::getOp()
{
    return operador;
}