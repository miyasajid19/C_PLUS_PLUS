#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> sumStore;

public:
    int kthLargestSum(vector<int> arr, int k) {
        if (k > arr.size()) return -1;  // Return -1 if k is out of bounds

        sumStore.clear();  // Clear previous sums

        // Generate all subarray sums
        for (int i = 0; i < arr.size(); i++) {
            int sum = 0;
            for (int j = i; j < arr.size(); j++) {
                sum += arr[j];
                sumStore.push_back(sum);  // Store the sum of subarray arr[i...j]
            }
        }

        // Sort the sums in ascending order
        sort(sumStore.begin(), sumStore.end());

        // Return the kth largest sum
        return sumStore[sumStore.size() - k];
    }
};

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    vector<int> arr = {-3, -2, -1, 0, 1, 2, 3, 4};
    Solution soln;

    // Iterate over k from 1 to arr.size(), printing the kth largest sum
    for (int i = 1; i <= arr.size(); i++) {
        cout << "When k = " << i << ", the kth largest sum is " << soln.kthLargestSum(arr, i) << endl << endl;
    }

    return EXIT_SUCCESS;
}
