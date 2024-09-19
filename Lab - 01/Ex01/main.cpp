#include <iostream>

using namespace std;

// Función para calcular la suma del cubo de los dígitos de un número
int sumaCubosDigitos(int numero)
{
    int suma = 0;
    while (numero > 0)
    {
        int digito = numero % 10;         // Obtener el último dígito
        suma += digito * digito * digito; // Sumar el cubo del dígito
        numero /= 10;                     // Quitar el último dígito
    }
    return suma;
}

// Función para verificar si un número es un cubo perfecto (Armstrong)
bool esCuboPerfecto(int numero)
{
    return numero == sumaCubosDigitos(numero);
}

int main()
{
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;

    if (esCuboPerfecto(numero))
    {
        cout << numero << " es un cubo perfecto (número Armstrong)." << endl;
    }
    else
    {
        cout << numero << " no es un cubo perfecto." << endl;
    }

    return 0;
}
