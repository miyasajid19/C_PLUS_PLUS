#include <iostream>
#include <cstdlib>
using namespace std;

class Heap {
private:
    int size;
    int capacity;
    int *arr;

    // Private method to heapify the subtree rooted at index for a min-heap
    void heapify(int arr[], int size, int index) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        int smallestIndex = index;

        // Find the smallest among index, left child, and right child
        if (leftIndex < size && arr[smallestIndex] > arr[leftIndex]) {
            smallestIndex = leftIndex;
        }
        if (rightIndex < size && arr[smallestIndex] > arr[rightIndex]) {
            smallestIndex = rightIndex;
        }

        // If the smallest element is not at index, swap and continue heapifying
        if (smallestIndex != index) {
            swap(arr[smallestIndex], arr[index]);
            heapify(arr, size, smallestIndex);
        }
    }

public:
    // Constructor to build a min-heap from an array
    Heap(int arr1[], int size) {
        this->size = size;
        this->capacity = size;
        this->arr = arr1;

        // Build the heap by calling heapify in reverse order
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(arr, size, i);
        }
    }

    // Destructor (no need to delete arr since it's external)
    ~Heap() {}

    // Method to print the heap elements
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int arr[6] = {12, -3, 1, 3, 12, 23};
    Heap heap1(arr, 6);

    cout << "Min-Heap built from the array: ";
    heap1.print();

    return EXIT_SUCCESS;
}
