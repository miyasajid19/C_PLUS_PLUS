#include <iostream>
#include <cstdlib>
using namespace std;

class Heap {
public:
    void heapify(int arr[], int size, int index) {
        int largest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < size && arr[largest] < arr[leftIndex])
            largest = leftIndex;
        if (rightIndex < size && arr[largest] < arr[rightIndex])
            largest = rightIndex;

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }

    void sortArr(int arr[], int size) {
        // Build heap
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }

        // Extract elements from heap
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int arr[6] = {1, 3, 4, 25, 2, 312};
    Heap heap;

    cout << "Original array: ";
    for (int i = 0; i < 6; i++)
        cout << arr[i] << "\t";
    cout << endl;

    heap.sortArr(arr, 6);

    cout << "Sorted array: ";
    for (int i = 0; i < 6; i++)
        cout << arr[i] << "\t";
    cout << endl;

    return EXIT_SUCCESS;
}
