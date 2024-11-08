#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "ListaEnlazada.h"

void threadEliminar(ListaEnlazada &lista)
{
    for (int i = 0; i < 10; ++i)
    {
        int valor = rand() % 20;
        lista.eliminar(valor);
    }
}

void threadInsertar(ListaEnlazada &lista)
{
    for (int i = 0; i < 10; ++i)
    {
        int valor = rand() % 20;
        lista.insertar(valor);
    }
}

void threadBuscar(ListaEnlazada &lista)
{
    for (int i = 0; i < 10; ++i)
    {
        int valor = rand() % 20;
        lista.buscar(valor);
    }
}

void threadModificar(ListaEnlazada &lista)
{
    for (int i = 0; i < 10; ++i)
    {
        int valorAntiguo = rand() % 20;
        int incremento = rand() % 10 + 1;
        lista.modificar(valorAntiguo, incremento);
    }
}

int main()
{
    srand(time(0));
    ListaEnlazada lista;

    std::thread t1(threadEliminar, std::ref(lista));
    std::thread t2(threadInsertar, std::ref(lista));
    std::thread t3(threadBuscar, std::ref(lista));
    std::thread t4(threadModificar, std::ref(lista));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
