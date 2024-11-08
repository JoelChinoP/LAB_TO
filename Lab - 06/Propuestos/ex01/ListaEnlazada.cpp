#include "ListaEnlazada.h"
#include <thread>
#include <sstream>

ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

void ListaEnlazada::insertar(int valor)
{
    std::lock_guard<std::mutex> lock(mtx);
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;

    std::stringstream ss;
    ss << std::this_thread::get_id();
    std::cout << "**thread insertar " << ss.str()
              << "**: Insertando: " << valor << std::endl;
}

void ListaEnlazada::eliminar(int valor)
{
    std::lock_guard<std::mutex> lock(mtx);
    Nodo *temp = cabeza;
    Nodo *anterior = nullptr;

    while (temp && temp->dato != valor)
    {
        anterior = temp;
        temp = temp->siguiente;
    }

    std::stringstream ss;
    ss << std::this_thread::get_id();

    if (temp)
    {
        if (anterior)
        {
            anterior->siguiente = temp->siguiente;
        }
        else
        {
            cabeza = temp->siguiente;
        }
        delete temp;
        std::cout << "**thread eliminar " << ss.str()
                  << "**: Eliminando: " << valor << std::endl;
    }
    else
    {
        std::cout << "**thread eliminar " << ss.str()
                  << "**: No se eliminó " << valor << std::endl;
    }
}

Nodo *ListaEnlazada::buscar(int valor)
{
    std::lock_guard<std::mutex> lock(mtx);
    Nodo *temp = cabeza;

    while (temp && temp->dato != valor)
    {
        temp = temp->siguiente;
    }

    std::stringstream ss;
    ss << std::this_thread::get_id();

    if (temp)
    {
        std::cout << "**thread buscar " << ss.str()
                  << "**: Buscado: " << valor << std::endl;
    }
    else
    {
        std::cout << "**thread buscar " << ss.str()
                  << "**: No encontrado: " << valor << std::endl;
    }
    return temp;
}

void ListaEnlazada::modificar(int valorAntiguo, int incremento)
{
    std::lock_guard<std::mutex> lock(mtx);
    Nodo *nodo = buscar(valorAntiguo);

    std::stringstream ss;
    ss << std::this_thread::get_id();

    if (nodo)
    {
        int nuevoValor = nodo->dato + incremento;
        std::cout << "**thread modificar " << ss.str()
                  << "**: Modificando " << valorAntiguo << " a "
                  << nuevoValor << std::endl;
        nodo->dato = nuevoValor;
    }
    else
    {
        std::cout << "**thread modificar " << ss.str()
                  << "**: No se encontró " << valorAntiguo << std::endl;
    }
}