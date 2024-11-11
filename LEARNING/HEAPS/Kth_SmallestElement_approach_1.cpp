#include <iostream>
#include <cstdlib>
using namespace std;
class Heap
{
    int *arr;
    int size;
    int capacity;
    void heapify(int arr[], int size, int index)
    {
        int largest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        if (leftIndex < size and arr[largest] < arr[leftIndex])
            largest = leftIndex;
        if (rightIndex < size and arr[largest] < arr[rightIndex])
            largest = rightIndex;
        if (largest != index)
        {
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }

public:
    int getKthSmallest(int arr[], int size, int k)
    {
        // creating the heap array for the given array
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arr, size, i);

        // now sorting the array
        for (int i = size - 1; i >= 0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
        return arr[k - 1];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[6] = {432, 407, 420, 433, 434, 436};
    cout << "Unsorted :: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    Heap heap;
    cout << "The 3rd smallest in the array is " << heap.getKthSmallest(arr, 6, 3) << "\n";

    cout << "Sorted :: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return EXIT_SUCCESS;
}