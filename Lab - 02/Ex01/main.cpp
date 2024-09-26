#include "calculadora.hpp"

int main()
{
    char operacion[50];
    std::cout << "Ingrese la operación: ";
    std::cin.getline(operacion, 50);

    OperacionAnalizador analizador;
    OperacionesMatematicas admin;
    ProcesadorOperacion procesador;

    // Analizar operadores
    char *operadores = analizador.analizar(operacion);

    // Administrar operandos
    int numOperandos = 0;
    double *operandos = admin.administrar(operacion, numOperandos);

    // Procesar la operación
    double resultado = procesador.procesar(operandos, operadores, numOperandos);

    // Mostrar resultado
    std::cout << "Resultado: " << resultado << std::endl;

    // Liberamos memoria
    delete[] operadores;
    delete[] operandos;

    return 0;
}
