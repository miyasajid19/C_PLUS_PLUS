#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

class solution
{
    // Define a function to reset sumstore each time KthLargestSum is called
    priority_queue<int, vector<int>, greater<int>> sumstore;

public:
    int KthLargestSum(vector<int> arr, int k)
    {
        // Clear the priority queue each time the function is called
        sumstore = priority_queue<int, vector<int>, greater<int>>();//this was the cause for giving error in testing
        
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                if (sumstore.size() < k)
                {
                    sumstore.push(sum);
                }
                else
                {
                    if (sum > sumstore.top())
                    {
                        sumstore.pop();
                        sumstore.push(sum);
                    }
                }
            }
        }
        return sumstore.top();
    }
};

int main()
{
    vector<int> arr = {-3, -2, -1, 0, 1, 2, 3, 4};
    solution soln;

    // Iterate over k from 1 to arr.size(), printing the kth largest sum
    for (int i = 1; i <= arr.size(); i++)
    {
        cout << "When k = " << i << ", the kth largest sum is " << soln.KthLargestSum(arr, i) << endl
             << endl;
    }
    return EXIT_SUCCESS;
}
