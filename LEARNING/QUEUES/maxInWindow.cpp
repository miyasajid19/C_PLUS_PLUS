// You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window 
// moves right by one position.
// Return the max sliding window.
// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> MaxInWindow(vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq;  // This will store indices

    // First process the first k elements
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result.push_back(arr[dq.front()]);

    // Process the rest of the elements
    for (int i = k; i < arr.size(); ++i) {
        // Remove elements not in the window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        // Maintain the decreasing order in deque
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};  // Example test case
    int k = 3;  // Window size

    cout << "Input array: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> result = MaxInWindow(arr, k);

    cout << "Max in each window: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
