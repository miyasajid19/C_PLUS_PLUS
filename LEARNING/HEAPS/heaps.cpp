#include <iostream>
#include <cstdlib>
using namespace std;
class heap
{
    int *arr;
    int size;
    int capacity;

public:
    heap(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->size=0;
    }
    ~heap()
    {
        delete []arr;
    }
    void insert(int value)
    {
        this->size += 1;
        int index = this->size;
        arr[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= this->size; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
heap heap1(10);
heap1.insert(50);
heap1.insert(55);
heap1.insert(53);
heap1.insert(52);
heap1.insert(54);
heap1.print();

    return EXIT_SUCCESS;
}