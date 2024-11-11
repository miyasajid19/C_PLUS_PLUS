#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Heap
{
private:
    vector<int> arr;
    int size;

    // Private heapify function to maintain max-heap property
    void heapify(int index)
    {
        int largest = index;
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;

        if (leftIndex <= size && arr[leftIndex] > arr[largest])
            largest = leftIndex;

        if (rightIndex <= size && arr[rightIndex] > arr[largest])
            largest = rightIndex;

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    int Kth_largest_sum_Subarray(int size, int k)
    {
        vector<int> sumArr;
        for (int i = 1; i <= size; i++)
        {
            int sum = 0;
            for (int j = i; j <= size; j++)
            {
                sum += arr[j];
                sumArr.push_back(sum);
            }
        }
        sort(sumArr.rbegin(), sumArr.rend()); // Sort in descending order
        return (k > 0 && k <= sumArr.size()) ? sumArr[k - 1] : -1;
    }

    int Kth_largest_sum_Subarray_optimized(int size, int k)
    {
        priority_queue<int, vector<int>, greater<int>> Queue;
        for (int i = 1; i <= size; i++)
        {
            int sum = 0;
            for (int j = i; j <= size; j++)
            {
                sum += arr[j];
                if (Queue.size() < k)
                    Queue.push(sum);
                else if (Queue.top() < sum)
                {
                    Queue.pop();
                    Queue.push(sum);
                }
            }
        }
        return Queue.size() == k ? Queue.top() : -1;
    }

public:
    // Constructor to initialize max-heap from array
    Heap(vector<int> &inputArr)
    {
        this->size = inputArr.size() - 1;
        this->arr = inputArr;

        for (int i = size / 2; i >= 1; i--)
            heapify(i);
    }

    // Insert new value into heap
    void insert(int value)
    {
        if (size >= arr.size() - 1)
        {
            cout << "Heap overflow. Cannot insert more elements." << endl;
            return;
        }

        arr[++size] = value;
        int index = size;

        while (index > 1 && arr[index / 2] < arr[index])
        {
            swap(arr[index / 2], arr[index]);
            index /= 2;
        }
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty. No element to delete." << endl;
            return;
        }

        arr[1] = arr[size--];
        heapify(1);
    }

    void print() const
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << "\t";
        cout << endl;
    }

    int Kth_Largest_Sum_Subarray(int k)
    {
        return Kth_largest_sum_Subarray(size, k);
    }

    int Kth_Largest_Sum_Subarray_optimized(int k)
    {
        return Kth_largest_sum_Subarray_optimized(size, k);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr = {-1, 1, 2, 3, 4, 5 - 1, -3, -10}; // 1-based indexing

    Heap heap(arr);
    cout << "Heap after building from array: ";
    heap.print();

    heap.insert(60);
    cout << "Heap after inserting 60: ";
    heap.print();

    heap.deleteRoot();
    cout << "Heap after deleting root: ";
    heap.print();

    int k_values[] = {1, 2, 3};
    for (int k : k_values)
    {
        cout << "The " << k << "th largest subarray sum is: "
             << heap.Kth_Largest_Sum_Subarray(k) << endl;
        cout << "The " << k << "th largest subarray sum (optimized) is: "
             << heap.Kth_Largest_Sum_Subarray_optimized(k) << endl;
    }

    return EXIT_SUCCESS;
}
