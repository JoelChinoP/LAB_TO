#include <iostream>
using namespace std;

template <typename mitipo>
mitipo aritmetica(mitipo x, mitipo y)
{
    return x + y;
}

int main()
{
    int resultadoInt = aritmetica<int>(10, 45);
    double resultadoDouble = aritmetica<double>(3.45, 8.10);
    float resultadoFloat = aritmetica<float>(0.14f, 0.147f);

    cout << "Resultado int: " << resultadoInt << endl;
    cout << "Resultado double: " << resultadoDouble << endl;
    cout << "Resultado float: " << resultadoFloat << endl;

    return 0;
}
