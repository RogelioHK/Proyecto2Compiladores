/**
 * @author Adrian Ulises Mercado Martínez
 * @version 1, 3/11/2021
 */
#include "Quad.hpp"
#include <iostream>
Quad::Quad(/* args */)
{
}

Quad::Quad(string op, string arg1, string arg2, string res)
{
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->res = res;
}

Quad::~Quad()
{
}

QuadType Quad::resolveQuad(){
    if(op == "||") return QDIYUN;
    if(op == "&&") return QCONJUN;
    if(op == "==") return QIGUAL;
    if(op == "!=") return QDIST;
    if(op == "!") return QNEG;

    if(op == ">") return QMAYQ;
    if(op == "<") return QMINQ;
    if(op == ">=") return QMAYI;
    if(op == "<=") return QMINI;

    if(op == "+") return QMAS;
    if(op == "-") return QMENOS;
    if(op == "*") return QMUL;
    if(op == "/") return QDIV;
    if(op == "=") return QCOPY;
    if(op == "if") return QIF;
    if(op == "goto") return QGOTO;
    if(op == "label") return QLABEL;
    if(op == "(double)") return QCASTDOUBLE;
    if(op=="(float)") return QCASTFLOAT;
    if(op=="(int)") return QCASTINT;

    if(op=="printInt") return QPINT;
    if(op=="printFloat") return QPFLOAT;
    if(op=="printDouble") return QPDOUBLE;
    if(op=="printChar") return QPCHAR;

    if(op=="scanInt") return QSINT;
    if(op=="scanFloat") return QSFLOAT;
    if(op=="scanDouble") return QSDOUBLE;
    if(op=="scanChar") return QSCHAR;

    if(op == "return") return QRETURN;
    return QSIN;
}

void Quad::print()
{
    switch(resolveQuad()){
        case QMAS: 
        case QMENOS:
        case QMUL:
        case QDIV:
        case QMAYQ:
        case QMAYI:
        case QMINQ:
        case QMINI:
        case QDIYUN: 
        case QCONJUN: 
        case QIGUAL: 
        case QDIST:
            cout<<res<<"="<<arg1<<op<<arg2<<endl;
            break;
        case QIF:
            cout<<op<<" "<<arg1<<" goto "<<res<<endl;
            break;
        case QGOTO:
            cout<<op<<" "<<res<<endl;
            break;
        case QCOPY:
        case QNEG:
        case QCHAR:
            cout<<res<<op<<arg1<<endl;
            break;
        case QLABEL:
            cout<<res<<":\n";
            break;
        case QCASTDOUBLE:
        case QCASTFLOAT:
        case QCASTINT:
            cout<<res<<"="<<op<<arg1<<endl;
            break;
        case QPINT:
        case QPFLOAT:
        case QPDOUBLE:
        case QPCHAR:
            cout<<"print"<<" "<<res<<endl;
            break;
        case QSINT:
        case QSFLOAT:
        case QSDOUBLE:
        case QSCHAR:
            cout<<"scan"<<" "<<res<<endl;
            break;
        case QRETURN:
            cout<<"return"<<" "<<res<<endl;
            break;
        default:
            cout<<"Algo va mal con: "<<resolveQuad()<<endl;
            break;
    }
}


string Quad::getRes()
{
    return res;
}

string Quad::getArg1()
{
    return arg1;
}

string Quad::getArg2()
{
    return arg2;
}

string Quad::getOp()
{
    return op;
}