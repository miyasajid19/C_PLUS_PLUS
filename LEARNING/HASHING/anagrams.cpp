#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;
class Solution
{
    map<char, int> table;

public:
    Solution(string str)
    {
        for (char x : str)
            table[x]++;
    }
    friend bool checkAnagrams(Solution, Solution);
};
bool checkAnagrams(Solution s1, Solution s2)
{
    if (s1.table.size() != s2.table.size())
        return false;

    for (auto x : s1.table)
    {
        if (x.second != s2.table[x.first])
            return false;
    }
    return true;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Solution soln1("sajid");
    Solution soln2("dijas");
    cout<<boolalpha;
    cout << checkAnagrams(soln1, soln2);

    return EXIT_SUCCESS;
}