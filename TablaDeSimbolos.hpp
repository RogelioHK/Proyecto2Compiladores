#ifndef __TABLADESIMBOLOS_HPP__
#define __TABLADESIMBOLOS_HPP__

#include <string>
#include <vector>
#include <map>

using namespace std;

#include "Sim.hpp"

class TablaDeSimbolos{
private:
    map<string, Sim> simbolos;
public:
    TablaDeSimbolos();
    ~TablaDeSimbolos();
    void addSim(string id, Sim s);
    int getDireccion(string id);
    int getTipo(string id);
    string getCat(string id);
    vector<int> getArgumentos(string id);
    bool is_in(string id);
    map<string,Sim> getSims();
};

#endif // !__SYMTAB_HPP__