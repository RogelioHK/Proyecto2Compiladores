#ifndef __TIPOTAB_HPP__
#define __TIPOTAB_HPP__

#include <map>
#include <string>
using namespace std;

#include "Tipo.hpp"

class TipoTab{
private:
    map<int,Tipo> tipos;
public:
    TipoTab();
    ~TipoTab();
    void addTipo(int id, string nombre, int tam);
    void addTipo(int id, string nombre, int items,  int base);
    void addTipo(int id, string nombre, TablaDeSimbolos *tab);
    int getTam(int id);
    int getItems(int id);
    TablaDeSimbolos *getTab(int id);
    int getBase(int id);
    string getNombre(int id);
};

#endif // !__TYPETAB_HPP__