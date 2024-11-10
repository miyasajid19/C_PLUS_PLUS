#include <iostream>
#include <cstdlib>

using namespace std;

class Heap
{
private:
    int *arr;
    int size;
    int capacity;

public:
    // Constructor to initialize heap with given capacity
    Heap(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity + 1]; // +1 to make space for 1-based indexing
        this->size = 0;                    // Initialize size to 0
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
        int index = 1;
        while (index <= size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;

            // Compare with left child
            if (leftIndex <= size && arr[leftIndex] > arr[largestIndex])
            {
                largestIndex = leftIndex;
            }
            // Compare with right child
            if (rightIndex <= size && arr[rightIndex] > arr[largestIndex])
            {
                largestIndex = rightIndex;
            }

            // If the largest element is not at the current index, swap and continue heapifying
            if (largestIndex != index)
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
            else
            {
                break;
            }
        }
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
};
void heapify(int arr[], int size, int index)
{
    int largest = index;
    int leftindex = 2 * index;
    int rightindex = 2 * index + 1;
    if (leftindex < size and arr[largest] < arr[leftindex])
    {
        largest = leftindex;
    }
    else if (rightindex < size and arr[largest] < arr[rightindex])
    {
        largest = rightindex;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Heap heap(10);
    heap.insert(50);
    heap.insert(55);
    heap.insert(53);
    heap.insert(52);
    heap.insert(54);

    cout << "Heap after insertions: ";
    heap.print();

    heap.deleteRoot();
    cout << "Heap after deleting root: ";
    heap.print();
    int arr[6] ={-1, 50, 55, 53, 52, 54};
     heapify(arr, 6, 1);
    for (int i =1;i<6;i++)
        cout<<arr[i]<<"\t";
    return EXIT_SUCCESS;
}
