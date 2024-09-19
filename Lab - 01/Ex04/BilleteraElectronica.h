#ifndef BILLETERAELECTRONICA_H
#define BILLETERAELECTRONICA_H

#include <string>

const int MAX_PRODUCTOS = 100; // Máximo número de productos que se pueden agregar al carrito

class BilleteraElectronica
{
private:
    double saldo;
    std::string productosCarrito[MAX_PRODUCTOS];
    int numeroProductos;
    int numeroProductosComprados;

public:
    // Constructor
    BilleteraElectronica();

    // Métodos de la clase
    void agregarProducto(const std::string& producto);
    void comprar();
    void recargarSaldo(double monto);
    double obtenerSaldo() const;
    int obtenerNumeroProductosCarrito() const;
    int obtenerNumeroProductosComprados() const;
};

#endif
