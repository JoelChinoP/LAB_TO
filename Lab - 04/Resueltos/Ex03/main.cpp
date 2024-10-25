#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Función lambda
    int (*s)(int) = [](int valor)
    { return valor + 3; };

    int u = 5;
    cout << s(u) << endl;

    // Función lambda para recorrer un vector
    vector<int> v = {5, 2, 3, 7, 1, 0, 14, 20};
    for_each(v.begin(), v.end(), [](int valor)
             { cout << valor << " "; });

    return 0;
}
