#include <iostream>
#include <cstdlib>
#include <set>
#include <iterator>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    // Set with default ordering (ascending)
    set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    cout << "Size of set1: " << set1.size() << endl;
    set1.insert(1); // Duplicate insertion
    cout << "Size of set1 after duplicate insertion: " << set1.size() << endl;

    // Print elements of set1
    for (const auto &elem : set1)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Set with custom ordering (descending)
    set<int, greater<int>> set2;
    for (int i = 0; i < 10; i++)
    {
        set2.insert(i);
    }

    // Print elements of set2
    for (const auto &value : set2)
    {
        cout << value << " ";
    }
    cout << endl;

    // Remove an element by value
    set2.erase(6);
    for (const auto &value : set2)
    {
        cout << value << " ";
    }
    cout << endl;

    // Remove the first element
    auto itr1 = set2.begin();
    set2.erase(itr1);
    for (const auto &value : set2)
    {
        cout << value << " ";
    }
    cout << endl;

    // Remove the last element
    auto itr2 = set2.end();
    if (itr2 != set2.begin())
    {
        advance(itr2, -1);
        set2.erase(itr2);
    }
    for (const auto &value : set2)
    {
        cout << value << " ";
    }
    cout << endl;
    // itr one is no longer pointing to the beginning of the set
    itr1 = set2.begin();
    advance(itr1, 3);
    itr2 = set2.end();
    advance(itr2, -2);
    set2.erase(itr1, itr2);

    for (auto value : set2)
    {
        cout << value << " ";
    }
    cout << endl;
    cout << set2.size() << endl;
    cout << boolalpha << set2.empty() << endl;
    set2.erase(set2.begin(), set2.end());
    cout << boolalpha << set2.empty() << endl;

    // set1
    itr2 = set1.find(3);
    cout << *itr2 << endl;
    itr2 = set1.find(432);
    if (itr2 == set1.end())
    {
        cout << "element is not present" << endl;
    }
    itr1 = set1.lower_bound(2);
    cout << *itr1 << endl;
    itr1 = set1.lower_bound(0);
    cout << *itr1 << endl;
    itr1 = set1.upper_bound(2);
    cout << *itr1 << endl;
    return EXIT_SUCCESS;
}
