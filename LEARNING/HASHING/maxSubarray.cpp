#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArrayLength(vector<int> arr)
    {
        unordered_map<int, int> table; // Maps prefix sums to their earliest index
        int prefixsum = 0;
        int maxlength = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            prefixsum += arr[i];

            // If prefix sum is zero, subarray from the start to the current index has a sum of zero
            if (prefixsum == 0)
            {
                maxlength = i + 1;
            }

            // If prefix sum has been seen before, calculate the subarray length
            if (table.find(prefixsum) != table.end())
            {
                maxlength = max(maxlength, i - table[prefixsum]);
            }
            else
            {
                // Store the first occurrence of the prefix sum
                table[prefixsum] = i;
            }
        }
        return maxlength;
    }
};

int main()
{
    Solution soln;
    vector<int> arr = {1, 2, -3, 3, -1, 2, -2, 4, -4, 1};
    cout << "Maximum subarray length with sum 0: " << soln.maxSubArrayLength(arr) << endl;
    return EXIT_SUCCESS;
}
