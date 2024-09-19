#include "BilleteraElectronica.h"
#include <iostream>

using namespace std;

// Constructor
BilleteraElectronica::BilleteraElectronica()
{
    saldo = 0.0;
    numeroProductos = 0;
    numeroProductosComprados = 0;
}

// Método para agregar producto al carrito
void BilleteraElectronica::agregarProducto(const std::string &producto)
{
    if (numeroProductos < MAX_PRODUCTOS)
    {
        productosCarrito[numeroProductos++] = producto;
        cout << producto << " ha sido agregado al carrito." << endl;
    }
    else
    {
        cout << "El carrito está lleno. No se puede agregar más productos." << endl;
    }
}

// Método para realizar la compra
void BilleteraElectronica::comprar()
{
    if (numeroProductos == 0)
    {
        cout << "El carrito está vacío. No hay nada para comprar." << endl;
        return;
    }

    double totalCompra = numeroProductos * 10.0; // Supongamos que cada producto cuesta 10.0
    if (saldo >= totalCompra)
    {
        saldo -= totalCompra;
        numeroProductosComprados += numeroProductos;
        numeroProductos = 0; // Limpiar el carrito
        cout << "Compra realizada con éxito. Tu saldo actual es: " << saldo << endl;
    }
    else
    {
        cout << "Saldo insuficiente para realizar la compra." << endl;
    }
}

// Método para recargar saldo
void BilleteraElectronica::recargarSaldo(double monto)
{
    saldo += monto;
    cout << "Tu saldo ha sido recargado. Saldo actual: " << saldo << endl;
}

// Método para obtener el saldo actual
double BilleteraElectronica::obtenerSaldo() const
{
    return saldo;
}

// Método para obtener el número de productos en el carrito
int BilleteraElectronica::obtenerNumeroProductosCarrito() const
{
    return numeroProductos;
}

// Método para obtener el número de productos comprados
int BilleteraElectronica::obtenerNumeroProductosComprados() const
{
    return numeroProductosComprados;
}
