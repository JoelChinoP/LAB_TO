#ifndef AUTOMOVIL_BUILDER_H
#define AUTOMOVIL_BUILDER_H
#include "Builder.h"
#include <sstream>

class AutomovilBuilder : public Builder
{
private:
    Automovil *automovil;

public:
    AutomovilBuilder() { reset(); }
    ~AutomovilBuilder() { delete automovil; }

    void reset()
    {
        automovil = new Automovil("", "", "", 0.0);
    }

    void definirModelo(const std::string &modelo) override
    {
        automovil = new Automovil(modelo, "", "", 0.0);
    }

    void definirMotorizacion(const std::string &motorizacion) override
    {
        automovil->agregarComponente(Componente("Motor", motorizacion));
    }

    void definirPais(const std::string &pais) override
    {
        automovil->agregarComponente(Componente("País de origen", pais));
    }

    void definirPrecio(double precio) override
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << precio;
        automovil->agregarComponente(Componente("Precio base", "$" + ss.str()));
    }

    void agregarComponente(const std::string &tipo, const std::string &especificacion) override
    {
        automovil->agregarComponente(Componente(tipo, especificacion));
    }

    Automovil *obtenerAutomovil() override
    {
        Automovil *resultado = automovil;
        automovil = nullptr;
        reset();
        return resultado;
    }
};
#endif