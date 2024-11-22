#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"

class Director {
private:
    Builder* builder;

public:
    void setBuilder(Builder* b) {
        builder = b;
    }

    Automovil* construirAutomovilEconomico() {
        builder->definirModelo("Económico");
        builder->definirMotorizacion("Motor 1.0L");
        builder->definirPais("Perú");
        builder->definirPrecio(10000);
        builder->agregarComponente("Puertas", "Blanco");
        builder->agregarComponente("Asientos", "Negro");
        return builder->obtenerAutomovil();
    }

    Automovil* construirAutomovilDeportivo() {
        builder->definirModelo("Deportivo");
        builder->definirMotorizacion("Motor 3.0L Turbo");
        builder->definirPais("Alemania");
        builder->definirPrecio(50000);
        builder->agregarComponente("Puertas", "Rojo");
        builder->agregarComponente("Asientos", "Cuero Negro");
        builder->agregarComponente("Llantas", "Deportivas");
        return builder->obtenerAutomovil();
    }
};

#endif
