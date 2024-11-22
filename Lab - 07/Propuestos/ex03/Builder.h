#ifndef BUILDER_H
#define BUILDER_H

#include "Automovil.h"

class Builder {
public:
    virtual ~Builder() {}
    virtual void definirModelo(const std::string& modelo) = 0;
    virtual void definirMotorizacion(const std::string& motorizacion) = 0;
    virtual void definirPais(const std::string& pais) = 0;
    virtual void definirPrecio(double precio) = 0;
    virtual void agregarComponente(const std::string& tipo, const std::string& color) = 0;
    virtual Automovil* obtenerAutomovil() = 0;
};

#endif
