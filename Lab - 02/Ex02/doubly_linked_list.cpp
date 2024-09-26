#include "doubly_linked_list.hpp"
#include <iostream>

using namespace std;

// Node constructor
Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

// DoublyLinkedList constructor
DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
}

// Destructor para liberar toda la memoria utilizada
DoublyLinkedList::~DoublyLinkedList()
{
    while (!isEmpty())
    {
        deleteAtBeginning();
    }
}

// Insertar al principio
void DoublyLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insertar al final
void DoublyLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insertar en una posición
void DoublyLinkedList::insertAtPosition(int data, int position)
{
    if (position < 1)
    {
        cout << "Position should be >= 1." << endl;
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(data);
        return;
    }
    Node *newNode = new Node(data);
    Node *temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Position greater than the number of nodes." << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Eliminar al principio
void DoublyLinkedList::deleteAtBeginning()
{
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
}

// Eliminar al final
void DoublyLinkedList::deleteAtEnd()
{
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }
    Node *temp = head;
    if (temp->next == nullptr)
    {
        head = nullptr;
        delete temp;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

// Eliminar en una posición
void DoublyLinkedList::deleteAtPosition(int position)
{
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }
    Node *temp = head;
    for (int i = 1; temp != nullptr && i < position; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Position is greater than the number of nodes." << endl;
        return;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}

// Imprimir en orden hacia adelante
void DoublyLinkedList::printListForward()
{
    Node *temp = head;
    cout << "Forward List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Imprimir en orden inverso
void DoublyLinkedList::printListReverse()
{
    Node *temp = head;
    if (temp == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    cout << "Reverse List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Verificar si la lista está vacía
bool DoublyLinkedList::isEmpty() const
{
    return head == nullptr;
}
