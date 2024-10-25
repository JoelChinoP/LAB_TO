#include <iostream>
#include <vector>
#include <algorithm> // Para std::count_if
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
using namespace std;

int main()
{
    srand(std::time(0));

    vector<int> numeros(20);
    for (int &num : numeros)
    {
        num = std::rand() % 100;
    }

    int cuenta_impares = count_if(numeros.begin(), numeros.end(), [](int n)
                                  { return n < 20 && n % 2 != 0; });

    cout << "El número de impares menores de 20 es: " << cuenta_impares << endl;

    cout << "Números generados: ";
    for (int num : numeros)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
