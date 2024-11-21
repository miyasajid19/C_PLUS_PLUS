#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> results;
        results.push_back(0);
        string digits;
        for (int i = 1; i <= n; i++)
        {
            digits="";
            char bits;
            int num = i;
            int bit;
            while (num != 0)
            {
                 bit = num | 1;
                num=num>>1;
            }
            results.push_back(bit);
            digits.erase();
        }
        return results;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Solution a;
    vector<int> bits = a.countBits(5);
    for (auto x : bits)
    {
        cout << x << endl;
    }
    return EXIT_SUCCESS;
}