#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
    priority_queue<int, vector<int>, greater<int>> MinHeap;

public:
    vector<int> merge(vector<vector<int>> K_arrays)
    {
        for (vector<int> temp : K_arrays)
        {
            for (auto x : temp)
            {
                MinHeap.push(x);
            }
        }
        vector<int> ans;
        while (not MinHeap.empty())
        {
            ans.push_back(MinHeap.top());
            MinHeap.pop();
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> arr1 = {-3, -2, -1};
    vector<int> arr2 = {-0, 1};
    vector<int> arr3 = {1, 2, 3};
    vector<int> arr4 = {-55, -40, 40, 100};
    vector<int> arr5 = {7, 13, 39, 407, 432};
    vector<vector<int>> arr = {arr1, arr2, arr3, arr4, arr5};
    Solution soln;
    vector<int> merged = soln.merge(arr);
    for (auto x : merged)
        cout << x << '\t';
    return EXIT_SUCCESS;
}
//second approach can be merging the array and add to min heap and then back to ans vector
//thrid approach can be make the helper function that merges two sorted array and make another function which takes k sized array vector and take two vectors and merge them with helper and again push back to the intial vector array and then if size==1 then return ans
