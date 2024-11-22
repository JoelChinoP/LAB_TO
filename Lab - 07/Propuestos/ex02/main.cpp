#include "Director.h"
#include "Cliente.h"
#include <iostream>

int main() {
    Director director;
    CuentaBuilder builder;
    director.setBuilder(&builder);

    Cliente cliente("Joel");

    auto cuentaAhorro = director.construirCuentaAhorro();
    cuentaAhorro->depositar(1000);
    cliente.agregarCuenta(cuentaAhorro);

    auto cuentaJoven = director.construirCuentaJoven();
    cuentaJoven->depositar(500);
    cliente.agregarCuenta(cuentaJoven);

    cliente.mostrarCuentas();

    cliente.calcularIntereses(1); // Intereses después de 1 año
    cliente.mostrarCuentas();

    return 0;
}
