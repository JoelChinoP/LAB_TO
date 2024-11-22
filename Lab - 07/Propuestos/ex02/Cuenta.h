#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

class Cuenta {
protected:
    std::string tipoCuenta;
    double saldo;
    double tasaInteres;

public:
    Cuenta(const std::string& tipo, double tasa) 
        : tipoCuenta(tipo), saldo(0.0), tasaInteres(tasa) {}

    virtual ~Cuenta() {}

    virtual void calcularInteres(double tiempo) = 0;
    virtual void mostrarEstado() const {
        std::cout << "Tipo: " << tipoCuenta << ", Saldo: " << saldo 
                  << ", Tasa: " << tasaInteres << "%" << std::endl;
    }

    void depositar(double cantidad) { saldo += cantidad; }
    void retirar(double cantidad) { if (cantidad <= saldo) saldo -= cantidad; }
};

class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro() : Cuenta("Ahorro", 0.45) {}
    void calcularInteres(double tiempo) override {
        saldo += saldo * (tasaInteres / 100) * tiempo;
    }
};

class CuentaJoven : public Cuenta {
public:
    CuentaJoven() : Cuenta("Joven", 1.0) {}
    void calcularInteres(double tiempo) override {
        saldo += saldo * (tasaInteres / 100) * tiempo;
    }
};

// Puedes agregar más tipos de cuenta según lo indicado: Pluss, Empresarial, etc.
#endif
