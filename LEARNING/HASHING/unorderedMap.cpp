#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    unordered_map<string, int> directory;
    directory.insert(make_pair("Uchiha Obito", 432));
    directory.insert(make_pair("Uchiha Obito", 1234)); // if duplicate value is detected in the index then it simply igores rather update unlike ordered map
    directory["Nohara Rin"] = 407;
    directory["Hatake Kakashi"] = 407432;
    directory.insert(make_pair("Uzumaki Naruto", 1));
    directory.insert(make_pair("Huguya Hinata", 2));
    directory.insert(make_pair("Uchiha Sasuke", 3));
    directory["Tsunade Senju"] = 4;
    directory.insert(make_pair("Namekaze Minato", 7));
    for (auto x : directory)
    {
        cout << "Name : " << x.first << " Contact No. : " << x.second << endl;
    }
    cout << endl;
    // deleting the element
    directory.erase("Nohara Rin"); // erasing via itertor
    for (auto x : directory)
    {
        cout << "Name : " << x.first << " Contact No. : " << x.second << endl;
    }
    cout << endl;

    // deleting the third element from first
    unordered_map<string, int>::iterator itr = directory.begin();
    advance(itr, 3);
    directory.erase(itr);
    for (auto x : directory)
    {
        cout << "Name : " << x.first << " Contact No. : " << x.second << endl;
    }
    cout << endl;
    // erasing the range
    unordered_map<string, int>::iterator itr1 = directory.begin();
    unordered_map<string, int>::iterator itr2 = directory.begin();
    advance(itr1, 1);
    advance(itr2, directory.size() - 1);
    directory.erase(itr1, itr2);

    for (auto x : directory)
    {
        cout << "Name : " << x.first << " Contact No. : " << x.second << endl;
    }
    cout << endl;

    // lets find some values with index
    itr = directory.find("Uchiha Obito");
    if (itr != directory.end())
    {
        cout << "Found :: " << itr->second << endl;
    }
    cout << endl;
    itr = directory.find("Huguya Hinata");
    if (itr != directory.end())
    {
        cout << "Found" << itr->second << endl;
    }
    else
    {
        cout << "not Found" << endl
             << endl;
    }

    // checking if value is present or not
    cout << boolalpha;
    bool x = directory.count("Hatake Kakashi");
    cout << "Kakashi ??? " << x << endl;
    x = directory.count("Uchiha Obito");
    cout << "Obito ??? " << x << endl;

    return EXIT_SUCCESS;
} 