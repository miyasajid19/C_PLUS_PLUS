#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution
{
public:
    int permutations(int x)
    {
        if (x == 0 || x == 1)
        {
            return 1;
        }
        return x * permutations(x - 1);
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<int> pattern;
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int y = permutations(i) / (permutations(j) * permutations(i - j));
                pattern.push_back(y);
            }
            result.push_back(pattern);
            pattern.clear();
        }
        return result;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Solution A;
    vector<vector<int>> res = A.generate(5);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << ' ';
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}