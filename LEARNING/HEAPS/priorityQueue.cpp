#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Priority queue for Max-Heap (default behavior)
    priority_queue<int> maxHeap;

    // Priority queue for Min-Heap using custom comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Adding some elements to both heaps
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(30);

    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(30);

    cout << "Max-Heap (Default):" << endl;
    // Printing elements in descending order for max-heap (largest first)
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " "; // top() returns the largest element
        maxHeap.pop();                // Remove the largest element
    }
    cout << endl;

    cout << "Min-Heap (Using Custom Comparator):" << endl;
    // Printing elements in ascending order for min-heap (smallest first)
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " "; // top() returns the smallest element
        minHeap.pop();                // Remove the smallest element
    }
    cout << endl;

    return 0;
}
