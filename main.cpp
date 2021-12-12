#include <iostream>
#include "Driver.hpp"

int main(int argc, char *argv[]){
	Driver drv;
	if(argc == 2){
		//drv.parse(argv[1]);
		drv.gen_lectura("a");
	}
	else{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
g++ -o Cuadrupla Cuadrupla.cpp
g++ -o Sim Sim.cpp
g++ -o TablaDeSimbolos TablaDeSimbolos.cpp --
g++ -o Tipo Tipo.cpp
g++ -o TipoTab TipoTab.cpp --
g++ -o Driver Driver.cpp -- 
g++ -o a main.cpp --
*/