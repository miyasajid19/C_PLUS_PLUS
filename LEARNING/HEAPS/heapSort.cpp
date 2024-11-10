#include <iostream>
#include <cstdlib>
using namespace std;
class Heap
{
public:
    void heapify(int arr[], int size, int index)
    {
        int largest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        if (leftIndex < size and arr[largest] < arr[leftIndex])
            largest = leftIndex;
        else if (rightIndex < size and arr[largest] < arr[rightIndex])
            largest = rightIndex;

        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            heapify(arr, size--, largest);
        }
    }
    void sortArr(int arr[], int size)
    {
        for (int i = size / 2; i >= 0; i--)
        {
            heapify(arr, size, i);
        }

        // extract elements from heap
        for (int i = size - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[6] = {1, 3, 4, 25, 2, 312};
    Heap heap;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << "\t";
    cout << endl;
    heap.sortArr(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return EXIT_SUCCESS;
}