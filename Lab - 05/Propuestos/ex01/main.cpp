#include <iostream>
#include <string>

// Nodo de la lista
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
};

// Lista enlazada
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Destructor
    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    // Insertar al final
    void insert(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // Mostrar lista
    void display()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Obtener tamaño
    int getSize() const
    {
        return size;
    }
};

// Función principal para probar
int main()
{
    // Lista de edades (enteros)
    LinkedList<int> ages;
    ages.insert(25);
    ages.insert(30);
    ages.insert(35);

    std::cout << "Lista de edades:" << std::endl;
    ages.display();

    // Lista de palabras (strings)
    LinkedList<std::string> words;
    words.insert("Hola");
    words.insert("Mundo");
    words.insert("C++");

    std::cout << "\nLista de palabras:" << std::endl;
    words.display();

    return 0;
}