#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
void combination(string str, int index, string current, vector<string> &result, vector<string> map)
{
    if (str.size() == index)
    {
        result.push_back(current);
        return;
    }
    int correspondingDigit = str[index] - '0';
    if (correspondingDigit <= 1)
    {
        combination(str, index + 1, current, result, map);
        return;
    }
    for (int i = 0; i < map[correspondingDigit].size(); i++)
    {
        combination(str, index + 1, current + map[correspondingDigit][i], result, map);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string str1;
    cout << "enter keypad numbers : " << endl;
    cin >> str1;
    combination(str1, 0, "", result, map);
    for (string str : result)
    {
        cout << str << "\n";
    }
    return EXIT_SUCCESS;
}