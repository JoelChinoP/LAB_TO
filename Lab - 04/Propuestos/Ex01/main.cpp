#include <iostream>
#include <vector>
#include <algorithm> // Para std::count_if
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()

int main() {
    std::srand(std::time(0));

    std::vector<int> numeros(20);
    for (int &num : numeros) {
        num = std::rand() % 100; 
    }

    int cuenta_impares = std::count_if(numeros.begin(), numeros.end(), [](int n) {
        return n < 20 && n % 2 != 0;
    });

    std::cout << "El número de impares menores de 20 es: " << cuenta_impares << std::endl;

    std::cout << "Números generados: ";
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
