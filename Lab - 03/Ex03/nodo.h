#ifndef NODO_H
#define NODO_H

#include <memory>

class Nodo
{
public:
    int valor;
    std::shared_ptr<Nodo> siguiente;            // Puntero hacia el siguiente nodo
    std::weak_ptr<Nodo> anterior;               // Puntero hacia el nodo anterior

    Nodo(int val) : valor(val), siguiente(nullptr), anterior() {}
    
    ~Nodo() {
        // Opcional: Mensaje al eliminar un nodo
        // std::cout << "\nNodo eliminado " << valor;
    }
};

#endif // NODO_H
