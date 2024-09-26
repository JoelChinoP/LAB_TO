#include "doubly_linked_list.hpp"
#include <iostream>

using namespace std;

int main()
{
    DoublyLinkedList list;

    // Insertando datos
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtPosition(15, 2);
    list.insertAtEnd(25);
    list.insertAtEnd(30);

    // Imprimir la lista
    cout << "After Insertions:" << endl;
    list.printListForward();
    list.printListReverse();

    // Eliminaciones
    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteAtPosition(2);

    cout << "After Deletions:" << endl;
    list.printListForward();
    list.printListReverse();

    return 0;
}
