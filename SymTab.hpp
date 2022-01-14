#ifndef __SYMTAB_HPP__
#define __SYMTAB_HPP__

#include <string>
#include <vector>
#include <map>
using namespace std;

#include "Sym.hpp"

class SymTab
{
private:
    vector<string> ids;
    map<string, Sym> syms;
public:
    SymTab();
    ~SymTab();
    string getId(int i);
    int size();
    void addSym(string id, Sym s);
    int getDir(string id);
    int getType(string id);
    string getCat(string id);
    vector<int> getArgs(string id);
    bool is_in(string id);
    map<string,Sym> getSyms();
    Sym getSym(string id);
};

#endif // !__SYMTAB_HPP__