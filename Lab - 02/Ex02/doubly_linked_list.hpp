#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data);
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void printListForward();
    void printListReverse();
    bool isEmpty() const;
};

#endif
