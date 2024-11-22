#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H
#include "Componente.h"
#include <vector>
#include <string>
#include <iomanip>

class Automovil
{
private:
    std::string modelo;
    std::string motorizacion;
    std::string pais;
    double precio;
    std::vector<Componente> componentes;

public:
    Automovil(const std::string &modelo, const std::string &motorizacion, const std::string &pais, double precio)
        : modelo(modelo), motorizacion(motorizacion), pais(pais), precio(precio) {}

    void agregarComponente(const Componente &componente)
    {
        componentes.push_back(componente);
    }

    void mostrar() const
    {
        std::cout << "\n=== Detalles del Automóvil ===" << std::endl;
        std::cout << "Modelo: " << modelo << std::endl;
        std::cout << "Motorización: " << motorizacion << std::endl;
        std::cout << "País de fabricación: " << pais << std::endl;
        std::cout << "Precio: $" << std::fixed << std::setprecision(2) << precio << std::endl;
        std::cout << "\nComponentes instalados:" << std::endl;
        std::cout << "------------------------" << std::endl;
        for (const auto &componente : componentes)
        {
            std::cout << "  ";
            componente.mostrar();
        }
        std::cout << std::endl;
    }
};
#endif