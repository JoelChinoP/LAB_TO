#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <string>
#include <iostream>

class Componente {
private:
    std::string tipo;
    std::string color;

public:
    Componente(const std::string& tipo, const std::string& color)
        : tipo(tipo), color(color) {}

    void mostrar() const {
        std::cout << tipo << " de color " << color << std::endl;
    }
};

#endif
