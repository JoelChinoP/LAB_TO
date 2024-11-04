#include <iostream>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node *top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        Node *temp = top;
        T value = temp->data;
        top = top->next;
        delete temp;
        size--;
        return value;
    }

    T peek() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    // Prueba con números
    Stack<int> numStack;
    std::cout << "Testing numeric stack:" << std::endl;

    numStack.push(10);
    numStack.push(20);
    numStack.push(30);

    std::cout << "Popping elements: ";
    while (!numStack.isEmpty())
    {
        std::cout << numStack.pop() << " ";
    }
    std::cout << std::endl;

    // Prueba con caracteres
    Stack<char> charStack;
    std::cout << "\nTesting character stack:" << std::endl;

    charStack.push('A');
    charStack.push('B');
    charStack.push('C');

    std::cout << "Popping elements: ";
    while (!charStack.isEmpty())
    {
        std::cout << charStack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}