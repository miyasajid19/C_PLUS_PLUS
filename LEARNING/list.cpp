#include <iostream>
#include <list>
#include <iterator> // For iterators
using namespace std;
int main() {
    // Note: list is implemented as a doubly linked list (DLL).
    
    // 1. Different ways of initializing a list
    list<int> list1;                       // Empty list
    list<int> list2(5);                    // List with 5 elements, initialized to 0
    list<int> list3(5, 10);                // List with 5 elements, each initialized to 10
    list<int> list4 = {1, 2, 3, 4, 5};     // List initialized with a list
    list<int> list5(list4);                // Copy constructor

    // Display lists
    cout << "list4: ";
    for (int x : list4) cout << x << " ";
    cout << endl;

    // 2. Push and Pop operations
    list1.push_back(10); // Add element at the end
    list1.push_back(20);
    list1.push_front(5); // Add element at the front
    cout << "After push_front and push_back: ";
    for (int x : list1) cout << x << " ";
    cout << endl;

    list1.pop_back(); // Remove last element
    list1.pop_front(); // Remove first element
    cout << "After pop_front and pop_back: ";
    for (int x : list1) cout << x << " ";
    cout << endl;

    // 3. Accessing elements
    cout << "First element using front(): " << list1.front() << endl;
    cout << "Last element using back(): " << list1.back() << endl;

    // 4. Erase operations
    list4.erase(list4.begin()); // Erase the first element
    cout << "After erasing first element: ";
    for (int x : list4) cout << x << " ";
    cout << endl;

    auto it = list4.begin();
    advance(it, 2); // Move iterator to the 3rd position
    list4.erase(list4.begin(), it); // Erase a range of elements
    cout << "After erasing range (first to 3rd position): ";
    for (int x : list4) cout << x << " ";
    cout << endl;

    // 5. Clear list
    list4.clear();
    cout << "After clear(), list4 size: " << list4.size() << endl;

    // 6. Resize list
    list3.resize(10, 99); // Resize to 10, filling new elements with 99
    cout << "After resize: ";
    for (int x : list3) cout << x << " ";
    cout << endl;

    // 7. Filling list with the same value
    list5.assign(7, 42); // Assign 7 elements with value 42
    cout << "After filling list5 with 42: ";
    for (int x : list5) cout << x << " ";
    cout << endl;

    // 8. Traversing a list
    // Using for loop (not index-based)
    cout << "Traversal using for loop: ";
    for (auto it = list3.begin(); it != list3.end(); ++it) cout << *it << " ";
    cout << endl;

    // Using for-each loop
    cout << "Traversal using for-each loop: ";
    for (int x : list3) cout << x << " ";
    cout << endl;

    // Using iterators
    cout << "Traversal using iterators: ";
    for (auto it = list3.begin(); it != list3.end(); ++it) cout << *it << " ";
    cout << endl;

    // Using reverse iterators
    cout << "Traversal using reverse iterators: ";
    for (auto rit = list3.rbegin(); rit != list3.rend(); ++rit) cout << *rit << " ";
    cout << endl;

    return 0;
}
