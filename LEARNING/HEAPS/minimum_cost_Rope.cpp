#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

class Heap
{
    vector<int> arr;

    // Corrected heapify function with reference and index bounds
    void heapify(vector<int> &arr, int size, int index)
    {
        int parentIndex = index;
        int LeftIndex = 2 * index + 1;
        int RightIndex = 2 * index + 2;

        if (LeftIndex < size && arr[LeftIndex] > arr[parentIndex])
            parentIndex = LeftIndex;
        if (RightIndex < size && arr[RightIndex] > arr[parentIndex])
            parentIndex = RightIndex;

        if (parentIndex != index)
        {
            swap(arr[parentIndex], arr[index]);
            heapify(arr, size, parentIndex);
        }
    }

public:
    Heap() {}

    void add(int value)
    {
        int index = arr.size();
        arr.push_back(value);

        while (index > 0)
        {
            int parentIndex = (index - 1) / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // Constructor to create a heap from a vector of elements
    Heap(vector<int> temp)
    {
        arr = temp;
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            heapify(arr, arr.size(), i);
    }

    void display()
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << '\t';
        cout << endl;
    }
    int FindCost()
    {
        priority_queue<int, vector<int>, greater<int>> MinHeap;
        for (auto x : arr)
            MinHeap.push(x);

        while (not MinHeap.empty())
        {
            if (MinHeap.size() == 1)
                return MinHeap.top();

            int a = MinHeap.top();
            MinHeap.pop();
            int b = MinHeap.top();
            MinHeap.pop();
            MinHeap.push(a + b);
        }
        return 0;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int>cost={1,13,4,8,62,61};
    Heap heap(cost);
    heap.display();
    cout<<"The minimum cost of the rope is "<<heap.FindCost();
    return EXIT_SUCCESS;
}
