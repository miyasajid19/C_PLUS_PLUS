#include <iostream>
#include <deque>
#include <iterator> // For iterators
using namespace std;
int main()
{
    // Note: deque is a double-ended queue with efficient front and back operations.

    // 1. Different ways of initializing a deque
    deque<int> deque1;                   // Empty deque
    deque<int> deque2(5);                // Deque with 5 elements, initialized to 0
    deque<int> deque3(5, 10);            // Deque with 5 elements, each initialized to 10
    deque<int> deque4 = {1, 2, 3, 4, 5}; // Deque initialized with a list
    deque<int> deque5(deque4);           // Copy constructor

    // Display deque4
    cout << "deque4: ";
    for (int x : deque4)
        cout << x << " ";
    cout << endl;

    // 2. Push and Pop operations
    deque1.push_back(10); // Add element at the end
    deque1.push_back(20);
    deque1.push_front(5); // Add element at the front
    cout << "After push_front and push_back: ";
    for (int x : deque1)
        cout << x << " ";
    cout << endl;

    deque1.pop_back();  // Remove last element
    deque1.pop_front(); // Remove first element
    cout << "After pop_front and pop_back: ";
    for (int x : deque1)
        cout << x << " ";
    cout << endl;

    // 3. Accessing elements
    cout << "First element using front(): " << deque1.front() << endl;
    cout << "Last element using back(): " << deque1.back() << endl;
    cout << "Second element using operator[]: " << deque4[1] << endl;
    cout << "Third element using at(): " << deque4.at(2) << endl;

    // 4. Erase operations
    deque4.erase(deque4.begin()); // Erase the first element
    cout << "After erasing first element: ";
    for (int x : deque4)
        cout << x << " ";
    cout << endl;

    auto it = deque4.begin();
    advance(it, 2);                   // Move iterator to the 3rd position
    deque4.erase(deque4.begin(), it); // Erase a range of elements
    cout << "After erasing range (first to 3rd position): ";
    for (int x : deque4)
        cout << x << " ";
    cout << endl;

    // 5. Clear deque
    deque4.clear();
    cout << "After clear(), deque4 size: " << deque4.size() << endl;

    // 6. Resize deque
    deque3.resize(10, 99); // Resize to 10, filling new elements with 99
    cout << "After resize: ";
    for (int x : deque3)
        cout << x << " ";
    cout << endl;

    // 7. Filling deque with the same value
    deque5.assign(7, 42); // Assign 7 elements with value 42
    cout << "After filling deque5 with 42: ";
    for (int x : deque5)
        cout << x << " ";
    cout << endl;

    // 8. Traversing a deque
    // Using for loop
    cout << "Traversal using for loop: ";
    for (auto it = deque3.begin(); it != deque3.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Using for-each loop
    cout << "Traversal using for-each loop: ";
    for (int x : deque3)
        cout << x << " ";
    cout << endl;

    // Using iterators
    cout << "Traversal using iterators: ";
    for (auto it = deque3.begin(); it != deque3.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Using reverse iterators
    cout << "Traversal using reverse iterators: ";
    for (auto rit = deque3.rbegin(); rit != deque3.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;

    return 0;
}
/*

Feature	            vector	                                    list (DLL)	            deque
Implementation	    Dynamic array	                            Doubly linked list	        Dynamic array of blocks
Insertion/Deletion	Inefficient in the middle	                Efficient at any position	Efficient at front and back
Access	            Fast random access	                        Sequential only (slow)	    Fast random access
Memory              Overhead	Less (contiguous memory)	    More (node pointers)	    Moderate (block management)
*/