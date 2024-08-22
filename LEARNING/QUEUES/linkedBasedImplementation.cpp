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
    Node *head;
    Node *tail;
    int capacity;
    int size;

public:
    Queue(int capacity) : head(nullptr), tail(nullptr), capacity(capacity), size(0) {}

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void Enqueue(int value)
    {
        if (isFull())
        {
            cout << "queue overflow" << endl;
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
        size++;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "queue underflow" << endl;
            return;
        }
        Node *temp = head;
        head = head->Next;
        delete temp; // free memory of the dequeued node
        size--;
        if (isEmpty())
        {
            tail = nullptr; // ensure tail is also null if the queue is empty
        }
    }

    int Peek()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1; // or another value to indicate an error
        }
        return head->value;
    }

    int Size()
    {
        return size;
    }
};

int main()
{
// Optional file I/O redirection
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Queue queue(5);
    for (int i=1;i<6;i++)
    {
        queue.Enqueue(i);
    }

    // Attempting to enqueue more elements than capacity
    queue.Enqueue(432); // should print "queue overflow"

    cout << "Front element: " << queue.Peek() << endl;

    queue.Dequeue();
    cout << "Front element after one dequeue: " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Front element after two dequeues: " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Front element after three dequeues: " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Front element after four dequeues: " << queue.Peek() << endl;
    queue.Dequeue();
    cout << "Front element after five dequeues: " << queue.Peek() << endl;
    queue.Dequeue(); // Should print "queue underflow"
    cout << "Front element after six dequeues: " << queue.Peek() << endl;

    return EXIT_SUCCESS;
}
