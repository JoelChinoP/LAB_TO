#include "rectangulo.h"

int main()
{
    // Instancias dinámicas con punteros inteligentes
    std::unique_ptr<Rectangulo> x = std::make_unique<Rectangulo>();  
    std::cout << "Dibujar(): \n";
    x->Dibujar();

    std::unique_ptr<Rectangulo> y = std::make_unique<Rectangulo>(30, 5);  
    std::cout << "Dibujar(30,5): \n";
    y->Dibujar();

    std::cout << "Dibujar(40,2): \n";
    x->Dibujar(40, 2);

    // Usando el constructor copia
    std::unique_ptr<Rectangulo> obj1 = std::make_unique<Rectangulo>(*x);
    std::cout << "Dibujar obj1 (constructor copia de x): \n";
    obj1->Dibujar();

    std::unique_ptr<Rectangulo> obj2 = std::make_unique<Rectangulo>(*y);
    std::cout << "Dibujar obj2 (constructor copia de y): \n";
    obj2->Dibujar();

    return 0;
}
