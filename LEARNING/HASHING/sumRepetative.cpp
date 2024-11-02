#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
class Solution
{
    map<int, int> table;

public:
    Solution(vector<int> arr)
    {
        for (auto i : arr)
        {
            table[i]++;
        }
    }

    int sumRepeated()
    {
        int sum = 0;
        for (auto x : table)
        {
            if (x.second > 1)
                sum += x.first;
        }
        return sum;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
vector<int> arr={1,1,2,2,3,3,3,4,4,5};
Solution soln(arr);
cout<<"The sum of Repeated Number is "<<soln.sumRepeated();

    return EXIT_SUCCESS;
}