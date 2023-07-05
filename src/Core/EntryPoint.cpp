#include "Engine.h"
#include <cstdlib>
#include <typeinfo>
#include <exception>
#include <iostream>
#include <ostream>


int main() {
    MyEngine::Engine e;

    try {
        e.Run();
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
