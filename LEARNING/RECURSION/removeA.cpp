#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string removeA(string str)
{
    string result;
    if (not str.length())
    {
        return "";
    }
    if (str[0] == 'a')
    {

        result += removeA(str.substr(1));
    }
    else
    {
        result += str[0] + removeA(str.substr(1));
    }
    return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string str;
    cout << "Enter the string: " << endl;
    getline(cin, str);

    string result = removeA(str);
    cout << "The resulting string is: " << result << endl;

    return EXIT_SUCCESS;
}