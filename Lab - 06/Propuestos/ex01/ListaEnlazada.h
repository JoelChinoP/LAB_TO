#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>
#include <mutex>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaEnlazada {
private:
    Nodo* cabeza;
    std::mutex mtx;

public:
    ListaEnlazada();
    void insertar(int valor);
    void eliminar(int valor);
    Nodo* buscar(int valor);
    void modificar(int valorAntiguo, int incremento);
};

#endif