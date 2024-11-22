#ifndef AUTOMOVIL_BUILDER_H
#define AUTOMOVIL_BUILDER_H

#include "Builder.h"

class AutomovilBuilder : public Builder {
private:
    Automovil* automovil;

public:
    AutomovilBuilder() { reset(); }
    ~AutomovilBuilder() { delete automovil; }

    void reset() {
        automovil = new Automovil("", "", "", 0.0);
    }

    void definirModelo(const std::string& modelo) override {
        automovil->agregarComponente(Componente("Modelo", modelo));
    }

    void definirMotorizacion(const std::string& motorizacion) override {
        automovil->agregarComponente(Componente("Motorización", motorizacion));
    }

    void definirPais(const std::string& pais) override {
        automovil->agregarComponente(Componente("Fabricado en", pais));
    }

    void definirPrecio(double precio) override {
        automovil->agregarComponente(Componente("Precio base", std::to_string(precio)));
    }

    void agregarComponente(const std::string& tipo, const std::string& color) override {
        automovil->agregarComponente(Componente(tipo, color));
    }

    Automovil* obtenerAutomovil() override {
        Automovil* resultado = automovil;
        reset();
        return resultado;
    }
};

#endif
