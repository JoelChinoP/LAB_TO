#include "lista.h"
#include <iostream>

int main()
{
    int arreglo[] = { 1,2,3,4,5,6,7,8,9,10 };
    const int longitud = sizeof(arreglo) / sizeof(*arreglo);

    Lista lista1; // Crear una instancia de Lista
    lista1.copiaArreglo(arreglo, longitud); // Copiar el arreglo a la lista

    // Imprimir la lista en ambas direcciones
    lista1.imprimeAdelante(); // Salida: 1 2 3 4 5 6 7 8 9 10
    lista1.imprimeAtras();    // Salida: 10 9 8 7 6 5 4 3 2 1

    // Buscar un valor desde adelante
    int valorBusqueda = 5;
    std::shared_ptr<Nodo> encontrado = lista1.buscarDesdeAdelante(valorBusqueda);
    if (encontrado)
        std::cout << "Valor " << valorBusqueda << " encontrado desde adelante.\n";
    else
        std::cout << "Valor " << valorBusqueda << " NO encontrado desde adelante.\n";

    // Buscar un valor desde atrás
    valorBusqueda = 11;
    encontrado = lista1.buscarDesdeAtras(valorBusqueda);
    if (encontrado)
        std::cout << "Valor " << valorBusqueda << " encontrado desde atrás.\n";
    else
        std::cout << "Valor " << valorBusqueda << " NO encontrado desde atrás.\n";

    // No es necesario destruir manualmente la lista, los punteros inteligentes lo harán

    return 0;
}
