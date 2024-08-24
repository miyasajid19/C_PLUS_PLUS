#include <iostream>
#include <cstdlib>
#include <set>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    set<string> Names;
    int *size;
    string *str;
    size = new int;
    str = new string;
    cout << "what is the upper bound for your data?" << endl;
    cin >> *size;
    cin.ignore();
    for (int i = 0; i < *size; i++)
    {
        cout << "name " << i + 1 << endl;
        getline(cin, *str);
        Names.insert(*str);
    }
    cout << endl
         << endl;
    cout << "there are " << Names.size() << " guests are joining the party" << endl;
    for (auto name : Names)
    {
        cout << name << endl;
    }
    return EXIT_SUCCESS;
}