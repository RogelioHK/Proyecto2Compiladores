
#include <iostream>
#include "Driver.hpp"

int main(int argc, char *argv[])
{    
    Driver drv;
    if (argc == 2)
    {
        drv.parse(argv[1]);
    }
    else
    {
        /** exit with failure condition **/
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}