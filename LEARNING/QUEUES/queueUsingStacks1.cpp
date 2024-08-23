#include <iostream>
#include <cstdlib>
using namespace std;

class Stacks
{
public:
    int size, capacity;
    int *arr = nullptr;

    Stacks(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~Stacks()
    {
        Erase();
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

    void Push_Back(int value)
    {
        if (isFull())
        {
            cout << "Overflow" << endl;
            return;
        }
        this->arr[size++] = value;
    }

    void Pop_Back()
    {
        if (isEmpty())
        {
            cout << "Underflow" << endl;
            return;
        }
        --size;
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return this->arr[this->size - 1];
    }

    int Size()
    {
        return this->size;
    }

    void Erase()
    {
        delete[] arr;
    }
};

class Queue : public Stacks
{
public:
    Queue(int capacity) : Stacks(capacity) {}

    void Enqueue(int value)
    {
        if (isFull())
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        Stacks temp(capacity);
        while (not isEmpty())
        {
            temp.Push_Back(Top());
            Pop_Back();
        }
        Push_Back(value);
        while (not temp.isEmpty())
        {
            Push_Back(temp.Top());
            temp.Pop_Back();
        }
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            return;
        }
        Pop_Back();
    }
    int Peek()
    {
        return Top();
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cout << boolalpha;

    // Create a queue with capacity 5
    Queue queue(5);
    
    // Check initial state of the queue
    cout << "Initial State of the Queue:" << endl;
    cout << "Is Empty: " << queue.isEmpty() << endl;
    cout << "Is Full: " << queue.isFull() << endl;
    cout << "Peek (should be undefined): " << queue.Peek() << endl;
    cout << "--------------------------------" << endl;

    // Enqueue elements into the queue
    cout << "Enqueueing elements:" << endl;
    queue.Enqueue(1);
    cout << "Peek after Enqueue(1): " << queue.Peek() << endl;
    queue.Enqueue(2);
    cout << "Peek after Enqueue(2): " << queue.Peek() << endl;
    queue.Enqueue(3);
    cout << "Peek after Enqueue(3): " << queue.Peek() << endl;
    queue.Enqueue(4);
    cout << "Peek after Enqueue(4): " << queue.Peek() << endl;
    queue.Enqueue(5);
    cout << "Peek after Enqueue(5): " << queue.Peek() << endl;

    // Attempt to enqueue when the queue is full
    cout << "Attempting to Enqueue(6) when full:" << endl;
    queue.Enqueue(6); // This should show queue overflow
    cout << "Peek after trying to Enqueue(6): " << queue.Peek() << endl;
    cout << "Is Empty: " << queue.isEmpty() << endl;
    cout << "Is Full: " << queue.isFull() << endl;
    cout << "--------------------------------" << endl;

    // Dequeue elements from the queue
    cout << "Dequeuing elements:" << endl;
    queue.Dequeue();
    cout << "Peek after Dequeue(): " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Peek after Dequeue(): " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Peek after Dequeue(): " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Peek after Dequeue(): " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Peek after Dequeue(): " << queue.Peek() << endl;

    // Attempt to dequeue when the queue is empty
    cout << "Attempting to Dequeue when empty:" << endl;
    queue.Dequeue(); // This should show queue underflow
    cout << "Peek after trying to Dequeue(): " << queue.Peek() << endl;
    cout << "Is Empty: " << queue.isEmpty() << endl;
    cout << "Is Full: " << queue.isFull() << endl;
    cout << "--------------------------------" << endl;

    return EXIT_SUCCESS;
}
