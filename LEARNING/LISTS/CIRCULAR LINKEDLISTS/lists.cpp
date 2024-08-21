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
    advance(ritr, 2);      // Advance by 2 positions
    cout << *ritr << endl; // Output: 3

    return EXIT_SUCCESS;
}
