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

    std::shared_ptr<Cuenta> construirCuentaAhorro() {
        builder->construirCuentaAhorro();
        return builder->obtenerCuenta();
    }

    std::shared_ptr<Cuenta> construirCuentaJoven() {
        builder->construirCuentaJoven();
        return builder->obtenerCuenta();
    }
};
#endif
