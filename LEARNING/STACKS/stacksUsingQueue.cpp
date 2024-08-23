#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int value) : value(value), Next(nullptr) {}
};

class Queue
{
public:
    Node *head;
    Node *tail;
    int capacity;
    int size;

    Queue(int capacity) : capacity(capacity), size(0), head(nullptr), tail(nullptr) {}

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int Size()
    {
        return size;
    }

    void Enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        Node *new_node = new Node(value);
        if (isEmpty())
        {
            head = tail = new_node;
        }
        else
        {
            tail->Next = new_node;
            tail = new_node;
        }
        ++size;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        delete temp;
        --size;
        if (isEmpty())
        {
            head = nullptr;
            tail = nullptr;
        }
    }

    int Peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return head->value;
    }
};

class Stack : public Queue
{
public:
    Stack(int capacity) : Queue(capacity) {}

    void Push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
            return;
        }
        // To simulate stack behavior, we need to move all elements
        // except the new one to the end of the queue.
        int size = this->size;
        Enqueue(value);
        for (int i = 0; i < size; ++i)
        {
            int front = head->value;
            Dequeue();
            Enqueue(front);
        }
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        Dequeue();
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->value;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    cout << boolalpha;

    // Create a stack with capacity 5
    Stack stack(5);

    // Check initial state of the stack
    cout << "Initial State of the Stack:" << endl;
    cout << "Is Empty: " << stack.isEmpty() << endl;
    cout << "Is Full: " << stack.isFull() << endl;
    cout << "Top (should be undefined): " << stack.Top() << endl;
    cout << "--------------------------------" << endl;

    // Push elements into the stack
    cout << "Pushing elements:" << endl;
    stack.Push(1);
    cout << "Top after Push(1): " << stack.Top() << endl;
    stack.Push(2);
    cout << "Top after Push(2): " << stack.Top() << endl;
    stack.Push(3);
    cout << "Top after Push(3): " << stack.Top() << endl;
    stack.Push(4);
    cout << "Top after Push(4): " << stack.Top() << endl;
    stack.Push(5);
    cout << "Top after Push(5): " << stack.Top() << endl;

    // Attempt to push when the stack is full
    cout << "Attempting to Push(6) when full:" << endl;
    stack.Push(6); // This should show stack overflow
    cout << "Top after trying to Push(6): " << stack.Top() << endl;
    cout << "Is Empty: " << stack.isEmpty() << endl;
    cout << "Is Full: " << stack.isFull() << endl;
    cout << "--------------------------------" << endl;

    // Pop elements from the stack
    cout << "Popping elements:" << endl;
    stack.Pop();
    cout << "Top after Pop(): " << stack.Top() << endl;
    stack.Pop();
    cout << "Top after Pop(): " << stack.Top() << endl;
    stack.Pop();
    cout << "Top after Pop(): " << stack.Top() << endl;
    stack.Pop();
    cout << "Top after Pop(): " << stack.Top() << endl;
    stack.Pop();
    cout << "Top after Pop(): " << stack.Top() << endl;

    // Attempt to pop when the stack is empty
    cout << "Attempting to Pop when empty:" << endl;
    stack.Pop(); // This should show stack underflow
    cout << "Top after trying to Pop(): " << stack.Top() << endl;
    cout << "Is Empty: " << stack.isEmpty() << endl;
    cout << "Is Full: " << stack.isFull() << endl;
    cout << "--------------------------------" << endl;

    return EXIT_SUCCESS;
}
