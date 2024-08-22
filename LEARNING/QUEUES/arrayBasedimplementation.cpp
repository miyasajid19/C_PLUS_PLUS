#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int size;
    int front;
    int back;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
        this->front = -1;
        this->back = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }

    void Enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        this->back++;
        arr[back] = data;
        size++;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        this->front++;
        size--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Indicating error or empty
        }
        return arr[front + 1];
    }

    int Size()
    {
        return this->size;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Queue queue(5);

    // Display queue operations and their results
    cout << "Queue operations demonstration:" << endl;

    // Enqueue operations
    cout << "Enqueueing 10 into the queue." << endl;
    queue.Enqueue(10);
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Enqueueing 20 into the queue." << endl;
    queue.Enqueue(20);
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Enqueueing 30 into the queue." << endl;
    queue.Enqueue(30);
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Enqueueing 40 into the queue." << endl;
    queue.Enqueue(40);
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Enqueueing 50 into the queue." << endl;
    queue.Enqueue(50);
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    // Try enqueueing when queue is full
    cout << "Trying to enqueue 60 into the queue (should fail as queue is full)." << endl;
    queue.Enqueue(60);

    // Dequeue operations
    cout << "Dequeuing from the queue." << endl;
    queue.Dequeue();
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Dequeuing from the queue." << endl;
    queue.Dequeue();
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Dequeuing from the queue." << endl;
    queue.Dequeue();
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    cout << "Dequeuing from the queue." << endl;
    queue.Dequeue();
    cout << "Current size of the queue: " << queue.Size() << endl;
    cout << "Front element: " << queue.peek() << endl;

    // Try dequeueing when queue is empty
    cout << "Trying to dequeue from the queue (should fail as queue is empty)." << endl;
    queue.Dequeue();

    // Final status
    cout << "Queue empty status: " << (queue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Queue full status: " << (queue.isFull() ? "Yes" : "No") << endl;

    cout << "End of the program." << endl;

    return EXIT_SUCCESS;
}
