#include <iostream>
#include <cstdlib>
using namespace std;
string keypad[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wzyx"};
void combinationstring(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = str[0];
    string code = keypad[ch - '0'];
    string remaining = str.substr(1);
    for (int i = 0; i < code.size(); i++)
    {
        combinationstring(remaining, ans + code[i]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "enter string" << endl;
    string str;
    cin >> str;
    cout << "possiible substrings are : " << endl;
    combinationstring(str, "");
    return EXIT_SUCCESS;
}