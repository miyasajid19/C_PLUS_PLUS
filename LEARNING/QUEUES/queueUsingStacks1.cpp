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
        if(isFull())
        {
            return;
        }
        Stacks temp(capacity);
        while(not isEmpty())
        {
            temp.Push_Back(Top());
            Pop_Back();
        }
        Push_Back(value);
        while(not temp.isEmpty())
        {
            Push_Back(temp.Top());
            temp.Pop_Back();
        }
    }
    void Dequeue()
    {
        if(isEmpty())
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
//#ifndef ONLINE_JUDGE
//    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
//#endif

    Queue queue(5); // Queue of capacity 5

    // Enqueue elements
    for (int i = 0; i < 6; i++) // Trying to enqueue 6 elements (overflow expected)
    {
        queue.Enqueue(i);
        if (!queue.isEmpty())
        {
            cout << "Front element after enqueue: " << queue.Peek() << endl << endl;
        }
    }

    // Dequeue elements
    for (int i = 0; i < 5; i++) // Dequeue all elements
    {
        queue.Dequeue();
        if (!queue.isEmpty())
        {
            cout << "Front element after dequeue: " << queue.Peek() << endl << endl;
        }
        else
        {
            cout << "Queue is empty after dequeue." << endl << endl;
        }
    }

    return EXIT_SUCCESS;
}