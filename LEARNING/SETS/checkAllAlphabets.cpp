#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
bool checkAlphabets(string str)
{
    if (str.size() < 26)
    {
        return false;
    }
    transform(str.begin(), str.end(), str.begin(),
              [](unsigned char c)
              { return tolower(c); });
    set<char> set1;
    for (auto x : str)
    {
        set1.insert(x);
    }

    return set1.size()==26;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string *str = nullptr;
    str = new string;
    cout << "enter  any string" << endl;
    getline(cin, *str);
    cout << boolalpha << checkAlphabets(*str) << endl;
    return EXIT_SUCCESS;
}