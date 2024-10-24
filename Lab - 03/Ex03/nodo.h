#ifndef NODO_H
#define NODO_H

#include <memory>

class Nodo
{
public:
    int valor;
    std::shared_ptr<Nodo> siguiente;        
    std::weak_ptr<Nodo> anterior;               

    Nodo(int val) : valor(val), siguiente(nullptr), anterior() {}
    
    ~Nodo() {
        //  Mensaje al eliminar un nodo
    }
};

#endif // NODO_H
