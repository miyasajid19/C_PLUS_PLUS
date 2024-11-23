#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> // for reverse iterator
using namespace std;
int main() {
    // 1. Different ways of initializing a vector
    vector<int> vec1;                      // Empty vector
    vector<int> vec2(5);                   // Vector with 5 elements, initialized to 0
    vector<int> vec3(5, 10);               // Vector with 5 elements, each initialized to 10
    vector<int> vec4 = {1, 2, 3, 4, 5};    // Vector initialized with a list
    vector<int> vec5(vec4);                // Copy constructor

    // Display vectors
    cout << "vec4: ";
    for (int x : vec4) cout << x << " ";
    cout << endl;

    // 2. Push and Pop operations
    vec1.push_back(10); // Add element at the end
    vec1.push_back(20);
    vec1.push_back(30);
    cout << "After push_back: ";
    for (int x : vec1) cout << x << " ";
    cout << endl;

    vec1.pop_back(); // Remove last element
    cout << "After pop_back: ";
    for (int x : vec1) cout << x << " ";
    cout << endl;

    // 3. Accessing elements
    cout << "First element using front(): " << vec1.front() << endl;
    cout << "Last element using back(): " << vec1.back() << endl;
    cout << "Second element using at(): " << vec1.at(1) << endl;
    cout << "Second element using []: " << vec1[1] << endl;

    // 4. Erase operations
    vec4.erase(vec4.begin()); // Erase the first element
    cout << "After erasing first element: ";
    for (int x : vec4) cout << x << " ";
    cout << endl;

    vec4.erase(vec4.begin(), vec4.begin() + 2); // Erase a range of elements
    cout << "After erasing first two elements: ";
    for (int x : vec4) cout << x << " ";
    cout << endl;

    // 5. Clear vector
    vec4.clear();
    cout << "After clear(), vec4 size: " << vec4.size()<< " and the capacity is still "<<vec4.capacity() << endl;

    // 6. Resize vector
    vec3.resize(10, 99); // Resize to 10, filling new elements with 99
    cout << "After resize: ";
    for (int x : vec3) cout << x << " ";
    cout << endl;

    // 7. Size and capacity
    cout << "Size of vec3: " << vec3.size() << endl;
    cout << "Capacity of vec3: " << vec3.capacity() << endl;

    // 8. Filling vector with the same value
    vec5.assign(7, 42); // Assign 7 elements with value 42
    cout << "After filling vec5 with 42: ";
    for (int x : vec5) cout << x << " ";
    cout << endl;

    // 9. Initializing an empty vector with 0
    vector<int> vec6(0); // Size is 0
    cout << "Size of vec6: " << vec6.size() << endl;

    // 10. Traversing a vector
    // Using for loop
    cout << "Traversal using for loop: ";
    for (size_t i = 0; i < vec3.size(); ++i) cout << vec3[i] << " ";
    cout << endl;

    // Using for-each loop
    cout << "Traversal using for-each loop: ";
    for (int x : vec3) cout << x << " ";
    cout << endl;

    // Using iterators
    cout << "Traversal using iterators: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) cout << *it << " ";
    cout << endl;

    // Using reverse iterators
    cout << "Traversal using reverse iterators: ";
    for (auto rit = vec3.rbegin(); rit != vec3.rend(); ++rit) cout << *rit << " ";
    cout << endl;

    return 0;
}
