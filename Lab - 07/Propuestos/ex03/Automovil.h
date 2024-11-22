#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "Componente.h"
#include <vector>
#include <string>

class Automovil {
private:
    std::string modelo;
    std::string motorizacion;
    std::string pais;
    double precio;
    std::vector<Componente> componentes;

public:
    Automovil(const std::string& modelo, const std::string& motorizacion, const std::string& pais, double precio)
        : modelo(modelo), motorizacion(motorizacion), pais(pais), precio(precio) {}

    void agregarComponente(const Componente& componente) {
        componentes.push_back(componente);
    }

    void mostrar() const {
        std::cout << "Modelo: " << modelo << ", Motorización: " << motorizacion
                  << ", País: " << pais << ", Precio: $" << precio << std::endl;
        std::cout << "Componentes:" << std::endl;
        for (const auto& componente : componentes) {
            componente.mostrar();
        }
    }
};

#endif
