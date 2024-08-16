#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

class Stacks
{
    int *arr;
    int capacity;
    int top;

public:
    // Constructor
    Stacks(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity]();
        this->top = -1;
    }

    // Destructor
    ~Stacks()
    {
        delete[] arr;
    }

    // Push method
    void Push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop method
    void pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return;
        }
        --top;
    }

    // Top method
    int Top() const
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return INT_MIN; // Return a special value to indicate stack is empty
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() const
    {
        return top == capacity - 1;
    }
};

int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Stacks stack(5);

    // Test the stack methods
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout << "Top element: " << stack.Top() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.Top() << endl;

    stack.Push(40);
    stack.Push(50);
    stack.Push(60);  // Should trigger stack overflow

    if (stack.isFull()) {
        cout << "Stack is full" << endl;
    }

    while (!stack.isEmpty()) {
        cout << "Popped element: " << stack.Top() << endl;
        stack.pop();
    }

    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    }

    return EXIT_SUCCESS;
}
