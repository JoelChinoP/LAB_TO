#include "Director.h"
#include "AutomovilBuilder.h"
#include <iostream>

int main()
{
    std::cout << "\n=== Sistema de Construcción de Automóviles ===\n"
              << std::endl;

    Director director;
    AutomovilBuilder builder;
    director.setBuilder(&builder);

    std::cout << "Construyendo automóvil económico..." << std::endl;
    Automovil *economico = director.construirAutomovilEconomico();
    economico->mostrar();
    delete economico;

    std::cout << "\nConstruyendo automóvil deportivo..." << std::endl;
    Automovil *deportivo = director.construirAutomovilDeportivo();
    deportivo->mostrar();
    delete deportivo;

    return 0;
}