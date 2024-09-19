#include <iostream>
#include <cstdlib> // Para usar rand()
using namespace std;

// Función para generar un número aleatorio dentro de un rango
int generarAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Función para calcular el promedio de edades
double calcularPromedio(int edades[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += edades[i];
    }
    return static_cast<double>(suma) / n;
}

// Función para obtener la mayor edad
int obtenerMayorEdad(int edades[], int n)
{
    int mayor = edades[0];
    for (int i = 1; i < n; i++)
    {
        if (edades[i] > mayor)
        {
            mayor = edades[i];
        }
    }
    return mayor;
}

// Función para contar la cantidad de personas por grado de instrucción
void contarInstruccion(int grados[], int n, int &primaria, int &secundaria, int &superior)
{
    primaria = secundaria = superior = 0;
    for (int i = 0; i < n; i++)
    {
        if (grados[i] == 1)
            primaria++;
        else if (grados[i] == 2)
            secundaria++;
        else if (grados[i] == 3)
            superior++;
    }
}

int main()
{
    int N;
    cout << "Ingrese la cantidad de personas (N): ";
    cin >> N;

    int edades[N];
    int gradosInstruccion[N];

    // Generar edades aleatorias (entre 15 y 80) y grados de instrucción (1-Primaria, 2-Secundaria, 3-Superior)
    for (int i = 0; i < N; i++)
    {
        edades[i] = generarAleatorio(15, 80);
        gradosInstruccion[i] = generarAleatorio(1, 3);
    }

    // Calcular promedio de edades
    double promedio = calcularPromedio(edades, N);
    // Obtener la mayor edad
    int mayorEdad = obtenerMayorEdad(edades, N);
    // Contar la cantidad de personas por grado de instrucción
    int primaria = 0, secundaria = 0, superior = 0;
    contarInstruccion(gradosInstruccion, N, primaria, secundaria, superior);

    // Mostrar resultados
    cout << "Promedio de edades: " << promedio << endl;
    cout << "Mayor edad: " << mayorEdad << endl;
    cout << "Cantidad de personas con instrucción Primaria: " << primaria << endl;
    cout << "Cantidad de personas con instrucción Secundaria: " << secundaria << endl;
    cout << "Cantidad de personas con instrucción Superior: " << superior << endl;

    return 0;
}
