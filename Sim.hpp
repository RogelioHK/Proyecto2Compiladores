#ifndef __Sim_HPP__
#define __Sim_HPP__

#include <string>
#include <vector>
using namespace std;

class Sim{
private:
    int direccion;
    int tipo;
    string cat;
    vector<int> argumentos;

public:
    Sim();
    Sim(int direccion, int tipo, string cat);
    Sim(int direccion, int tipo, vector<int> argumentos);
    ~Sim();

    int getDireccion();
    int getTipo();
    string getCat();
    vector<int> getArgumentos();  
};
#endif // !__SYM_HPP__