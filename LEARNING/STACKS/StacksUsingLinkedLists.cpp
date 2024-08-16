#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int value;
    Node *Next = nullptr;
    Node(int value)
    {
        this->value = value;
        this->Next = nullptr;
    }
    ~Node() {}
};

class Stacks
{
public:
    Node *head;
    int capacity;
    int size;
    Stacks(int capacity) : head(nullptr)
    {
        this->capacity = capacity;
        this->size = 0;
    }
    ~Stacks() {}

    void Push(int value)
    {
        if (size >= capacity)
        {
            cout << "Stack overflow: cannot push " << value << " as the stack is full." << endl;
            return;
        }

        Node *new_node = new Node(value);
        new_node->Next = head;
        head = new_node;
        size++;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void Top()
    {
        // if (!head)
        if (isFull())
        {
            cout << "The stack is empty; no top element to display." << endl;
            return;
        }
        cout << "Top element: " << head->value << endl;
    }

    void pop()
    {
        // if (!head)
        if (isEmpty())
        {
            cout << "Stack underflow: cannot pop from an empty stack." << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        delete temp;
        size--;
        cout << "Popped an element from the stack." << endl;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("..input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Stacks stack(5);

    cout << "Initial stack status:" << endl;
    cout << "Is stack empty? " << boolalpha << stack.isEmpty() << endl;
    cout << "Is stack full? " << boolalpha << stack.isFull() << endl;

    cout << "\nPerforming stack operations:" << endl;
    stack.Push(432);
    stack.Push(433);
    stack.Push(434);
    stack.Push(417);
    stack.Push(420);

    cout << "\nStack status after pushing 5 elements:" << endl;
    cout << "Is stack empty? " << boolalpha << stack.isEmpty() << endl;
    cout << "Is stack full? " << boolalpha << stack.isFull() << endl;

    stack.Top();

    stack.Push(407);

    cout << "\nPopping elements from the stack:" << endl;
    stack.pop();
    stack.pop();

    cout << "\nStack status after popping 2 elements:" << endl;
    cout << "Is stack empty? " << boolalpha << stack.isEmpty() << endl;
    cout << "Is stack full? " << boolalpha << stack.isFull() << endl;

    stack.Top();

    return EXIT_SUCCESS;
}
