#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <string>
#include <iostream>

class Componente {
private:
    std::string tipo;
    std::string especificacion;

public:
    Componente(const std::string& tipo, const std::string& especificacion)
        : tipo(tipo), especificacion(especificacion) {}

    void mostrar() const {
        std::cout << tipo << ": " << especificacion << std::endl;
    }
};
#endif