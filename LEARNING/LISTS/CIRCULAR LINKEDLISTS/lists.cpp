#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

int main() {
    // Initialize list1 with values
    list<int> list1 = {1, 2, 3, 4, 5};

    // Using a normal iterator to access elements
    auto itr = list1.begin();
    cout << *itr << endl; // Output: 1

    // Advance the iterator by 2 positions
    advance(itr, 2);
    cout << *itr << endl; // Output: 3

    // Using a reverse iterator to access elements
    auto ritr = list1.rbegin();
    cout << *ritr << endl; // Output: 5

    // Advance the reverse iterator by 2 positions
    advance(ritr, -2);
    cout << *ritr << endl; // Output: 3

    // Traversal using a range-based for loop
    cout << "List1 elements: ";
    for (auto val : list1) {
        cout << val << " ";
    }
    cout << endl;

    // Traversal using iterators
    cout << "List1 elements (iterator): ";
    for (auto itr1 = list1.begin(); itr1 != list1.end(); ++itr1) {
        cout << *itr1 << " ";
    }
    cout << endl;

    // Reverse traversal using reverse iterators
    cout << "List1 elements (reverse iterator): ";
    for (auto itr1 = list1.rbegin(); itr1 != list1.rend(); ++itr1) {
        cout << *itr1 << " ";
    }
    cout << endl;

    // Inserting elements into list2
    list<int> list2 = {1, 2, 4, 5};
    cout << "Initial list2 elements: ";
    for (auto val : list2) {
        cout << val << " ";
    }
    cout << endl;

    auto itr2 = list2.begin();
    advance(itr2, 2); // Move iterator to position where 3 will be inserted
    list2.insert(itr2, 3); // Insert 3 at the position

    cout << "List2 after insertion: ";
    for (auto val : list2) {
        cout << val << " ";
    }
    cout << endl;

    // Inserting multiple elements at the end
    list2.insert(list2.end(), 2, 432); // Insert 432 twice
    cout << "List2 after inserting 432 twice: ";
    for (auto val : list2) {
        cout << val << " ";
    }
    cout << endl;

    // Inserting a range of elements from list2 into list2 itself
    auto itr3 = list2.begin();
    auto itr4 = itr2;
    advance(itr4, 4); // Move itr4 to include the first 4 elements of list2

    // Insert elements from [itr3, itr4) at the beginning of list2
    list2.insert(list2.begin(), itr3, itr4);

    cout << "List2 after inserting range: ";
    for (auto val : list2) {
        cout << val << " ";
    }
    cout << endl;

    // Deleting a single element
    itr3 = list2.begin();
    advance(itr3, 2); // Move iterator to the element to be deleted
    list2.erase(itr3);

    cout << "List2 after deleting one element: ";
    for (auto val : list2) {
        cout << val << " ";
    }
    cout << endl;

    // Deleting a range of elements
    itr3 = list2.begin();
    advance(itr3, 4); // Move itr2 to the starting point of the range to be deleted
    advance(itr4, 6); // Move itr4 to the end point of the range to be deleted
    list2.erase(itr3, itr4); // Delete elements in the range [itr3, itr4)

    cout << "List2 after deleting range: ";
    for (auto val : list2) {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
