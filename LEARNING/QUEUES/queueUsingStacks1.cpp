#include <iostream>
using namespace std;

class Stack
{
public:
    int size, capacity;
    int *arr;

    Stack(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[size++] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        --size;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[size - 1];
    }

    int getSize()
    {
        return size;
    }
};

class Queue
{
private:
    Stack stack1, stack2;

public:
    Queue(int capacity) : stack1(capacity), stack2(capacity) {}

    void enqueue(int value)
    {
        if (stack1.isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        stack1.push(value);
    }

    void dequeue()
    {
        if (stack1.isEmpty() && stack2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (stack2.isEmpty())
        {
            while (!stack1.isEmpty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        stack2.pop();
    }

    int peek()
    {
        if (stack2.isEmpty())
        {
            while (!stack1.isEmpty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return stack2.top();
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Queue queue(5); // Queue of capacity 5

    // Enqueue elements
    for (int i = 0; i < 6; i++) // Trying to enqueue 6 elements (overflow expected)
    {
        queue.enqueue(i);
        if (queue.peek() != -1)
        {
            cout << "Front element after enqueue: " << queue.peek() << endl << endl;
        }
    }

    // Dequeue elements
    for (int i = 0; i < 5; i++) // Dequeue all elements
    {
        queue.dequeue();
        if (queue.peek() != -1)
        {
            cout << "Front element after dequeue: " << queue.peek() << endl << endl;
        }
        else
        {
            cout << "Queue is empty after dequeue." << endl << endl;
        }
    }

    return 0;
}
