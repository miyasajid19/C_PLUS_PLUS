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
            cout << "overflow" << endl;
            return;
        }
        this->arr[size++] = value;
    }
    void Pop_Back()
    {
        if (isEmpty())
        {
            cout << "underflow" << endl;
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
        return this->arr[this->size - 1]; // Fix to return the correct top element
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
class Queue:public Stacks{
    public:
Queue(int capacity) : Stacks(capacity) {}
    void Enqueue(int value)
    {
        Push_Back(value);
    }
    void Dequeue()
    {
        Stacks Temp(this->capacity);
        while (Size()!=1)
        {
            Temp.Push_Back(Top());
            Pop_Back();
        }
        Pop_Back();
        while(not Temp.isEmpty())
        {
            Push_Back(Temp.Top());
            Temp.Pop_Back();
        }
    }
    int Peek()
    {
        Stacks Temp(this->capacity);
        while (Size()!=1)
        {
            Temp.Push_Back(Top());
            Pop_Back();
        }
        int result=Top();
        
        while(not Temp.isEmpty())
        {
            Push_Back(Temp.Top());
            Temp.Pop_Back();
        }
        return result;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
Queue queue(5);
for(int i=0;i<6;i++)
{
    queue.Enqueue(i);
    cout<<queue.Peek()<<endl<<endl;
}
    queue.Dequeue();
    cout<<queue.Peek()<<endl<<endl;
    queue.Dequeue();
    cout<<queue.Peek()<<endl<<endl;
    queue.Dequeue();
    cout<<queue.Peek()<<endl<<endl;
    queue.Dequeue();
    cout<<queue.Peek()<<endl<<endl;
    queue.Dequeue();
    cout<<queue.Peek()<<endl<<endl;

    return EXIT_SUCCESS;
}