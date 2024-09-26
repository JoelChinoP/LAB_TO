#ifndef CALCULADORA_HPP
#define CALCULADORA_HPP

#include <iostream>
#include <cstring>
#include <cctype>

class OperacionAnalizador
{
public:
    char *analizar(const char *input);
};

class OperacionesMatematicas
{
public:
    double *administrar(const char *operacion, int &numOperandos);
};

class ProcesadorOperacion
{
public:
    double procesar(double *operandos, const char *operadores, int numOperandos);
};

#endif
