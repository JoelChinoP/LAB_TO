#ifndef CLIENTE_H
#define CLIENTE_H

#include "Cuenta.h"

class Cliente {
private:
    std::string nombre;
    std::vector<std::shared_ptr<Cuenta>> cuentas;

public:
    Cliente(const std::string& nombre) : nombre(nombre) {}

    void agregarCuenta(const std::shared_ptr<Cuenta>& cuenta) {
        cuentas.push_back(cuenta);
    }

    void mostrarCuentas() const {
        std::cout << "Cliente: " << nombre << std::endl;
        std::for_each(cuentas.begin(), cuentas.end(), [](const auto& cuenta) {
            cuenta->mostrarEstado();
        });
    }

    void calcularIntereses(double tiempo) {
        std::for_each(cuentas.begin(), cuentas.end(), [tiempo](auto& cuenta) {
            cuenta->calcularInteres(tiempo);
        });
    }
};
#endif
