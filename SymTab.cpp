#include "SymTab.hpp"

SymTab::SymTab()
{
}

SymTab::~SymTab()
{
}

/*
 * Agrega un símbolo a la tabla de símbolos
 */
void SymTab::addSym(string id, Sym s)
{
    syms[id] = s;
    ids.push_back(id);
}

Sym SymTab::getSym(string id)
{
    return syms[id];
}

/*******************************************************************************/
/*    Funciones para acceder a la información en la tabla de símbolos **********/
/*******************************************************************************/
int SymTab::size()
{
    return ids.size();
}

string SymTab::getId(int i)
{
    return ids.at(i);
}

int SymTab::getDir(string id)
{
    return syms[id].getDir();
}

int SymTab::getType(string id)
{
    return syms[id].getType();
}

string SymTab::getCat(string id)
{
    return syms[id].getCat();
}

vector<int> SymTab::getArgs(string id)
{
    return syms[id].getArgs();
}

bool SymTab::is_in(string id)
{
    map<string,Sym>::iterator it;
    it = syms.find(id);
    return it != syms.end();
}

map<string,Sym> SymTab::getSyms()
{
    return syms;
}