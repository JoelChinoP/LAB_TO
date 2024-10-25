#include <iostream>
using namespace std;

class infante
{
private:
    string nombre;

public:
    infante(const string &nom)
    {
        nombre = nom;
    }
    void gatear()
    {
        cout << nombre << " gateando..." << endl;
    }
};

class joven
{
private:
    string nombre;

public:
    joven(const string &nom)
    {
        nombre = nom;
    }
    void correr()
    {
        cout << nombre << " corriendo..." << endl;
    }
};

int main()
{

    infante inf("Juanito");
    joven jv("Pedrito");

    inf.gatear();
    jv.correr();

    return 0;
}