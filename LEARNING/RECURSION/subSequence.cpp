#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
void subSequence(string str, int index, string current, vector<string> &result)
{
    if (str.length() == index)
    {
        result.push_back(current);
        return;
    }
    subSequence(str, index + 1, current + str[index], result);
    subSequence(str, index + 1, current, result);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<string> result;
    string str;
    cout << "enter the string :: " << endl;
    cin >> str;
    cout<<"All possible subsequences are ::: "<<endl;
    subSequence(str, 0, "", result);
    for (auto c : result)
    {
        cout << c << " ";
    }
    return EXIT_SUCCESS;
}