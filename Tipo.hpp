#ifndef __TIPO_HPP__
#define __TIPO_HPP__
#include <string>
using namespace std;

#include "TablaDeSimbolos.hpp"

union TipoBase{
    TablaDeSimbolos *tab;
    int base;
};

class Tipo
{
private:
    string nombre;
    int tam;
    int items;
    bool  isTable;
    TipoBase base;
public:
    Tipo();
    Tipo(string nombre, int tam);
    Tipo(string nombre, TablaDeSimbolos *tab, int tam);
    Tipo(string nombre, int items, int base, int tam);
    ~Tipo();
    int getTam();
    TablaDeSimbolos *getTab();
    int getItems();
    int getBase();
    string getNombre();
};

#endif // !__TYPE_HPP__