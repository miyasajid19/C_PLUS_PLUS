#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Heap
{
private:
    int *arr;
    int size;
    int capacity;

    // Private heapify function to maintain max-heap property
    void heapify(int index)
    {
        int largest = index;
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;

        // Compare with left child
        if (leftIndex <= size && arr[leftIndex] > arr[largest])
        {
            largest = leftIndex;
        }
        // Compare with right child
        if (rightIndex <= size && arr[rightIndex] > arr[largest])
        {
            largest = rightIndex;
        }

        // If the largest element is not at the current index, swap and continue heapifying
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest); // Recursively heapify the affected subtree
        }
    }
    int Kth_largest_sum_Subarray(int temp[], int size, int k)
    {
        vector<int> sumArr;
        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = i; j < size; j++)
            {
                sum += arr[j];
                sumArr.push_back(arr[j]);
            }
        }
        sort(sumArr.begin(), sumArr.end());
        return sumArr[sumArr.size() - k];
    }

public:
    // Constructor to initialize an empty heap with a given capacity
    Heap(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity + 1]; // +1 to make space for 1-based indexing
        this->size = 0;                    // Initialize size to 0
    }

    // Constructor to initialize a max-heap from an existing array
    Heap(int *inputArr, int arraySize)
    {
        this->capacity = arraySize;
        this->size = arraySize;
        this->arr = new int[capacity + 1]; // +1 to make space for 1-based indexing

        // Copy elements from input array (assumes input array is 1-based indexed)
        for (int i = 1; i <= arraySize; i++)
        {
            arr[i] = inputArr[i];
        }

        // Apply heapify in reverse order to build max-heap
        for (int i = size / 2; i >= 1; i--) // size/2 to size are leaf nodes and they are already heap
        {
            heapify(i);
        }
    }

    // Destructor to free allocated memory
    ~Heap()
    {
        delete[] arr;
    }

    // Insert a new value into the heap
    void insert(int value)
    {
        if (size >= capacity)
        {
            cout << "Heap overflow. Cannot insert more elements." << endl;
            return;
        }

        // Increment size and insert the element at the end of the heap
        size++;
        int index = size;
        arr[index] = value;

        // Heapify upwards
        while (index > 1)
        {
            int parentIndex = index / 2;
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

    // Delete the root element (maximum element in a max heap)
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty. No element to delete." << endl;
            return;
        }

        // Replace root with the last element and reduce the heap size
        arr[1] = arr[size];
        size--;

        // Heapify downwards
        heapify(1);
    }

    // Print the elements of the heap
    void print() const
    {
        for (int i = 1; i <= size; i++)
        { // Start from index 1 for 1-based index
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
    int Kth_Largest_Sum_Subarray(int k)
    {
        return Kth_largest_sum_Subarray(arr, size, k % size);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    // Array for demonstration (1-based index)
    int arr[6] = {-1, 50, 5534234, 53, 52, 54}; // -1 is a placeholder for 1-based indexing
    int arraySize = 5;

    // Initialize the heap using the array and automatically apply the max-heap property
    Heap heap(arr, arraySize);

    cout << "Heap after building from array: ";
    heap.print();

    // Insert new values
    heap.insert(60);
    cout << "Heap after inserting 60: ";
    heap.print();

    // Delete the root
    heap.deleteRoot();
    cout << "Heap after deleting root: ";
    heap.print();
    heap.insert(10000);

    cout << "The " << 0 << "th largest subarray sum is: " << heap.Kth_Largest_Sum_Subarray(0) << endl;
    cout << "The " << 1 << "th largest subarray sum is: " << heap.Kth_Largest_Sum_Subarray(1) << endl;
    cout << "The " << 2 << "th largest subarray sum is: " << heap.Kth_Largest_Sum_Subarray(2) << endl;
    cout << "The " << 3 << "th largest subarray sum is: " << heap.Kth_Largest_Sum_Subarray(3) << endl;
    return EXIT_SUCCESS;
}
/*
if you want to implement 0 based indexing then the heapify function will be as
left=2*index+1;
right=2*index+2;

but the convenction is to use 1 based indexing
*/