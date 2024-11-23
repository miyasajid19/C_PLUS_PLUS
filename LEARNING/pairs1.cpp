#include <iostream>
#include <utility> // For std::pair
#include <vector>
using namespace std;

int main() {
    // 1. Different ways to initialize a pair
    pair<int, string> p1;                   // Default initialization
    pair<int, string> p2(1, "Apple");       // Initialization using constructor
    pair<int, string> p3 = {2, "Banana"};   // Initialization using initializer list
    pair<int, string> p4(p2);               // Copy constructor

    // 2. Accessing elements of a pair
    cout << "p2: (" << p2.first << ", " << p2.second << ")" << endl;
    cout << "p3: (" << p3.first << ", " << p3.second << ")" << endl;

    // 3. Modifying elements of a pair
    p1.first = 3;
    p1.second = "Cherry";
    cout << "Modified p1: (" << p1.first << ", " << p1.second << ")" << endl;

    // 4. Comparing pairs
    if (p2 < p3) { // Lexicographical comparison
        cout << "p2 is less than p3" << endl;
    } else {
        cout << "p2 is not less than p3" << endl;
    }

    // 5. Using make_pair() to create pairs
    pair<int, string> p5 = make_pair(4, "Date");
    cout << "p5: (" << p5.first << ", " << p5.second << ")" << endl;

    // 6. Nested pairs
    pair<int, pair<string, double>> nested_pair = {5, {"Elderberry", 9.99}};
    cout << "Nested Pair: (" << nested_pair.first 
         << ", (" << nested_pair.second.first 
         << ", " << nested_pair.second.second << "))" << endl;

    // 7. Pair in a container (e.g., vector of pairs)
    vector<pair<int, string>> vec = {{1, "Fig"}, {2, "Grape"}, {3, "Honeydew"}};
    cout << "Vector of pairs:" << endl;
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    // 8. Swapping pairs
    cout << "Before swapping: p2 = (" << p2.first << ", " << p2.second 
         << "), p3 = (" << p3.first << ", " << p3.second << ")" << endl;
    p2.swap(p3); // Swapping contents of p2 and p3
    cout << "After swapping: p2 = (" << p2.first << ", " << p2.second 
         << "), p3 = (" << p3.first << ", " << p3.second << ")" << endl;

    return 0;
}
