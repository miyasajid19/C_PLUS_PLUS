#include <iostream>
#include<cstdlib>
#include<vector>
using namespace std;
class Queue{
vector<int> arr;
int size;
int capacity;
public:
    Queue(int capacity)
    {
        this->capacity=capacity;
        this->size=-1;
    }
    bool isEmpty()
    {
        return size==-1;
    }
    bool isFull()
    {
        return size==capacity-1;
    }
    void Enqueue(int value)
    {
        if(isFull())
        {
            cout<<"queue overflowed"<<endl;
            return;
        }
        arr.push_back(value);
        size++;
    }
    int Peek()
    {
        if(isEmpty())
        {
            cout<<"the queue is empty";
            return -1;
        }
        return arr.front();
    }
    void Dequeue()
    {
        if(isEmpty())
        {
            cout<<"there is nothing to remove"<<endl;
            return;
        }
        arr.erase(arr.begin());
    }
    void clear()
    {
        arr.clear();
        size=-1;
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

    // Create a queue with capacity 5
    Queue queue(5);

    // Demonstrate Enqueue operation
    cout << "Enqueue operations:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Enqueue(" << i << "): ";
        queue.Enqueue(i);
        if (queue.isFull()) {
            cout << "Queue is full" << endl;
        } else {
            cout << "Enqueued " << i << endl;
        }
    }

    // Demonstrate Peek operation
    cout << "\nPeek operation:" << endl;
    cout << "Front element: " << queue.Peek() << endl;

    // Demonstrate Dequeue operation
    cout << "\nDequeue operations:" << endl;
    queue.Dequeue(); // Remove the front element
    cout << "After Dequeue, Front element: " << queue.Peek() << endl;

    // Enqueue more elements
    cout << "\nEnqueue operations after dequeue:" << endl;
    queue.Enqueue(6);
    queue.Enqueue(7);
    cout << "After Enqueueing 6 and 7:" << endl;
    cout << "Front element: " << queue.Peek() << endl;

    // Demonstrate Size function
    cout << "\nQueue size: " << queue.Size() << endl;

    // Clear the queue
    cout << "\nClearing the queue..." << endl;
    queue.clear();
    cout << "Queue cleared." << endl;
    cout << "Queue size after clearing: " << queue.Size() << endl;

    // Check if queue is empty
    cout << "\nIs queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // Try Peek and Dequeue on empty queue
    cout << "\nPeek on empty queue: " << queue.Peek() << endl;
    queue.Dequeue(); // This will show message as queue is empty

    return EXIT_SUCCESS;
}
