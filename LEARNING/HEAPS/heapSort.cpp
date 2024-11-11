#include <iostream>
#include <cstdlib>
using namespace std;

class Heap {
public:
    void heapify(int arr[], int size, int index) {
        int largest = index;
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        if (leftIndex < size && arr[leftIndex] > arr[largest]) {
            largest = leftIndex;
        }

        if (rightIndex < size && arr[rightIndex] > arr[largest]) {
            largest = rightIndex;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(arr, size, largest);
        }
    }

    void sortArr(int arr[], int size) {
        // Build heap (rearrange array)
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }

        // Extract elements from heap one by one
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0); // Heapify the reduced heap
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[6] = {1, 3, 4, 25, 2, 312};
    Heap heap;

    // Print initial array
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    // Sort the array
    heap.sortArr(arr, 6);

    // Print sorted array
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
