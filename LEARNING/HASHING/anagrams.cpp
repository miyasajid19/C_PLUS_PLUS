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

class solution
{
    map<char, int> table;

public:
    solution(string str1, string str2)
    {
        for (char x : str1)
        {
            table[x]++;
        }
        for (char x : str2)
        {
            table[x]--;
        }
    }
    bool checkAnagrams()
    {
        map<char, int>::iterator itr = table.begin();
        for (auto x : table)
        {
            if (x.second != itr->second)
                return false;
        }
        return true;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Solution soln1("sajid");
    Solution soln2("dijas");
    cout << boolalpha;
    cout << checkAnagrams(soln1, soln2);
    cout << endl;
    solution soln("sajid", "dijas");
    cout << soln.checkAnagrams();
    return EXIT_SUCCESS;
}