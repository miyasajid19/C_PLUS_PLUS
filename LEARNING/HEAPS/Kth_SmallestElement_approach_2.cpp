#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

/*
INTUITION:
1. Create a max heap of the first k elements.
2. For the remaining elements, if the current element is smaller than the heap's top,
   remove the top of the heap and insert the current element.
3. After processing all elements, the top of the heap will be the k-th smallest element.
*/

int findKthSmallest(int arr[],int size, int k)
{
    // Step 1: Create a max heap for the first k elements
    priority_queue<int> maxHeap;
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[i]);
    }

    // Step 2: Process remaining elements
    for (int i = k; i <size; i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {432, 407, 420, 433, 434, 436};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    cout << "The " << k << "-th smallest element in the array is: "
         << findKthSmallest(arr, size, k) << endl;

    return EXIT_SUCCESS;
}
