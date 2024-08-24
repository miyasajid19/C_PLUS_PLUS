#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Create an unordered_set
    unordered_set<int> set;

    // Insert elements
    set.insert(1);
    set.insert(2);
    set.insert(3);

    // Print elements
    cout << "Set elements: ";
    for (const auto& elem : set) {
        cout << elem << " ";
    }
    cout << endl;

    // Find an element
    auto it = set.find(2);
    if (it != set.end()) {
        cout << "Element 2 found" << endl;
    } else {
        cout << "Element 2 not found" << endl;
    }

    // Erase an element
    set.erase(2);

    // Check if the element is erased
    it = set.find(2);
    if (it == set.end()) {
        cout << "Element 2 successfully erased" << endl;
    }

    // Print elements again
    cout << "Set elements after erasure: ";
    for (const auto& elem : set) {
        cout << elem << " ";
    }
    cout << endl;

    // Additional operations
    // Insert more elements
    for (int i = 4; i < 10; ++i) {
        set.insert(i);
    }

    // Print elements
    cout << "Set elements after adding more elements: ";
    for (const auto& elem : set) {
        cout << elem << " ";
    }
    cout << endl;

    // Check size and emptiness
    cout << "Set size: " << set.size() << endl;
    cout << "Is set empty? " << boolalpha << set.empty() << endl;

    // Erase all elements
    set.clear();
    cout << "Is set empty after clearing? " << boolalpha << set.empty() << endl;

    return 0;
}
