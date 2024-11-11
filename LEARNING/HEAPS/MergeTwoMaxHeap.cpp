#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Heap {
    vector<int> arr;

    // Corrected heapify function with reference and index bounds
    void heapify(vector<int>& arr, int size, int index) {
        int parentIndex = index;
        int LeftIndex = 2 * index + 1;
        int RightIndex = 2 * index + 2;

        if (LeftIndex < size && arr[LeftIndex] > arr[parentIndex])
            parentIndex = LeftIndex;
        if (RightIndex < size && arr[RightIndex] > arr[parentIndex])
            parentIndex = RightIndex;

        if (parentIndex != index) {
            swap(arr[parentIndex], arr[index]);
            heapify(arr, size, parentIndex);
        }
    }

public:
    Heap() {}

    void add(int value) {
        int index = arr.size();
        arr.push_back(value);

        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (arr[parentIndex] < arr[index]) {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Constructor to create a heap from a vector of elements
    Heap(vector<int> temp) {
        arr = temp;
        for (int i = arr.size() / 2 - 1; i >= 0; i--)
            heapify(arr, arr.size(), i);
    }

    void display() {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << '\t';
        cout << endl;
    }

    friend Heap merge(Heap, Heap);
};

// Merges two heaps into one
Heap merge(Heap heap1, Heap heap2) {
    vector<int> ans = heap1.arr;
    ans.insert(ans.end(), heap2.arr.begin(), heap2.arr.end());

    return Heap(ans);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Heap heap1;
    heap1.add(407);
    heap1.add(432);
    heap1.add(433);
    heap1.add(4);
    heap1.add(436);
    heap1.add(420);
    heap1.display();

    Heap heap2;
    heap2.add(7);
    heap2.add(32);
    heap2.add(33);
    heap2.add(34);
    heap2.add(36);
    heap2.add(20);
    heap2.display();

    Heap heap = merge(heap1, heap2);
    heap.display();

    return EXIT_SUCCESS;
}
