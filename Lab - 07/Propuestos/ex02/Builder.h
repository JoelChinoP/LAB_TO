#ifndef BUILDER_H
#define BUILDER_H

#include "Cuenta.h"
#include <memory>

class Builder {
public:
    virtual ~Builder() {}
    virtual void construirCuentaAhorro() = 0;
    virtual void construirCuentaJoven() = 0;
    virtual std::shared_ptr<Cuenta> obtenerCuenta() = 0;
};

class CuentaBuilder : public Builder {
private:
    std::shared_ptr<Cuenta> cuenta;

public:
    void construirCuentaAhorro() override {
        cuenta = std::make_shared<CuentaAhorro>();
    }

    void construirCuentaJoven() override {
        cuenta = std::make_shared<CuentaJoven>();
    }

    std::shared_ptr<Cuenta> obtenerCuenta() override {
        return cuenta;
    }
};
#endif
