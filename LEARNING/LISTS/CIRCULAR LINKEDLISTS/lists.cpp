#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    list<int> list1 = {1, 2, 3, 4, 5};

    // Using normal iterator
    auto itr = list1.begin();
    cout << *itr << endl; // Output: 1

    // Advance the iterator correctly
    advance(itr, 2);      // Advance by 2 positions
    cout << *itr << endl; // Output: 3

    // Using reverse iterator
    auto ritr = list1.rbegin();
    cout << *ritr << endl; // Output: 5

    // Advance the reverse iterator correctly
    ritr += 2;            // Advance by 2 positions
    cout << *ritr << endl; // Output: 3

    // Traversal using ranged based loop
    for (auto val : list1)
    {
        cout << val << " ";
    }
    cout << endl;

    // Using iterators
    for (auto itr1 = list1.begin(); itr1 != list1.end(); ++itr1)
    {
        cout << *itr1 << " ";
    }
    cout << endl;

    // Reverse traversal using reverse iterators
    for (auto itr1 = list1.rbegin(); itr1 != list1.rend(); ++itr1)
    {
        cout << *itr1 << " ";
    }
    cout << endl;

    // Inserting elements into the list
    list<int> list2 = {1, 2, 4, 5};
    auto itr2 = list2.begin();
    for (auto val : list2)
    {
        cout << val << " ";
    }
    cout << endl;

    advance(itr2, 2);
    list2.insert(itr2, 3);
    for (auto val : list2)
    {
        cout << val << " ";
    }
    cout << endl;

    // Inserting the value count number of times
    list2.insert(list2.end(), 2, 432);
    for (auto val : list2)
    {
        cout << val << " ";
    }
    cout << endl;

    // Inserting a range of elements from list2 into list2 itself (fixed)
    auto itr3 = list2.begin();
    auto itr4 = itr2;
    advance(itr4, 4); // Advance __itr to include the first 4 elements of list2
    list2.insert(list2.begin(), itr3, itr4); // Insert the range at the beginning of list2

    for (auto val : list2)
    {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
