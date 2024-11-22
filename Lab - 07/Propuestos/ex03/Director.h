#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Builder.h"

class Director
{
private:
    Builder *builder;

public:
    void setBuilder(Builder *b)
    {
        builder = b;
    }

    Automovil *construirAutomovilEconomico()
    {
        builder->definirModelo("Modelo Económico Base");
        builder->definirMotorizacion("1.0L 4 cilindros");
        builder->definirPais("México");
        builder->definirPrecio(15000.00);
        builder->agregarComponente("Carrocería", "Sedán 4 puertas");
        builder->agregarComponente("Color exterior", "Blanco polar");
        builder->agregarComponente("Tapicería", "Tela negra");
        builder->agregarComponente("Rines", "Acero 15 pulgadas");
        return builder->obtenerAutomovil();
    }

    Automovil *construirAutomovilDeportivo()
    {
        builder->definirModelo("Modelo Sport GT");
        builder->definirMotorizacion("3.0L V6 Turbo");
        builder->definirPais("Alemania");
        builder->definirPrecio(55000.00);
        builder->agregarComponente("Carrocería", "Coupé 2 puertas");
        builder->agregarComponente("Color exterior", "Rojo metalizado");
        builder->agregarComponente("Tapicería", "Cuero premium negro");
        builder->agregarComponente("Rines", "Aleación 19 pulgadas");
        builder->agregarComponente("Kit deportivo", "Suspensión deportiva + Escape deportivo");
        return builder->obtenerAutomovil();
    }
};
#endif