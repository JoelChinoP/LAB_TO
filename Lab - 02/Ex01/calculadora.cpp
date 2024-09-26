#include "calculadora.hpp"

// Clase que analiza la operación y separa operandos y operadores
char *OperacionAnalizador::analizar(const char *input)
{
    int len = strlen(input);
    char *operadores = new char[len];
    int index = 0;

    for (int i = 0; i < len; ++i)
    {
        if (!isdigit(input[i]))
        {
            operadores[index++] = input[i];
        }
    }
    operadores[index] = '\0';
    return operadores;
}

// Clase que administra las operaciones matemáticas
double *OperacionesMatematicas::administrar(const char *operacion, int &numOperandos)
{
    double *operandos = new double[6];
    char *copia = new char[strlen(operacion) + 1];
    strcpy(copia, operacion);

    char *token = strtok(copia, "+-");
    while (token != nullptr && numOperandos < 6)
    {
        operandos[numOperandos++] = atof(token);
        token = strtok(nullptr, "+-");
    }
    delete[] copia;
    return operandos;
}

// Clase que procesa la operación calculando el resultado final
double ProcesadorOperacion::procesar(double *operandos, const char *operadores, int numOperandos)
{
    double resultado = operandos[0];

    for (int i = 1; i < numOperandos; ++i)
    {
        switch (operadores[i - 1])
        {
        case '+':
            resultado += operandos[i];
            break;
        case '-':
            resultado -= operandos[i];
            break;
        }
    }
    return resultado;
}
