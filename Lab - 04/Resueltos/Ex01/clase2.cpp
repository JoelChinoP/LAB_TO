#include <iostream>
using namespace std;

class Mamifero
{
public:
    Mamifero() : edad() { cout << "Constructor Mamifero..." << endl; }
    ~Mamifero() { cout << "Destructor Mamifero..." << endl; }
    void Move() { cout << "Mamifero move one step" << endl; }
    virtual void Speak() { cout << "Mamifero speak" << endl; }

protected:
    int edad;
};

class Dog : public Mamifero
{
public:
    Dog() : Mamifero() { cout << "Dog Constructor..." << endl; }
    ~Dog() { cout << "Dog Destructor..." << endl; }
    void WagTail() { cout << "Wagging Tail..." << endl; }
    void Move() { cout << "Dog move 5 steps..." << endl; }
    void Speak() { cout << "Woof!" << endl; }
};

int main()
{
    Mamifero m;
    Dog d;

    cout << "Calling Move()..." << endl;
    m.Move();
    d.Move();

    cout << "Calling Speak()..." << endl;
    m.Speak();
    d.Speak();

    return 0;
}