#include "Director.h"
#include "AutomovilBuilder.h"
#include <iostream>

int main() {
    Director director;
    AutomovilBuilder builder;

    director.setBuilder(&builder);

    std::cout << "Automóvil Económico:" << std::endl;
    Automovil* economico = director.construirAutomovilEconomico();
    economico->mostrar();
    delete economico;

    std::cout << "\nAutomóvil Deportivo:" << std::endl;
    Automovil* deportivo = director.construirAutomovilDeportivo();
    deportivo->mostrar();
    delete deportivo;

    return 0;
}
