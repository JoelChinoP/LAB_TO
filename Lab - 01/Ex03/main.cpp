#include <iostream>
using namespace std;

// Función para imprimir los divisores de un número y contar cuántos son
int imprimirDivisores(int numero)
{
    int contador = 0;
    cout << "Los divisores de " << numero << " son: ";
    for (int i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            cout << i << " "; // Imprimir el divisor
            contador++;       // Contar el divisor
        }
    }
    cout << endl;
    return contador;
}

int main()
{
    int numero;
    cout << "Ingrese un número: ";
    cin >> numero;

    // Llamar a la función para imprimir divisores y obtener la cantidad
    int cantidadDivisores = imprimirDivisores(numero);
    cout << "Cantidad de divisores: " << cantidadDivisores << endl;

    return 0;
}
