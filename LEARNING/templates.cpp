#include <iostream>
using namespace std;

// General template class
template <typename T>
class MyClass {
    T data;
public:
    MyClass(T val) : data(val) {}
    void display() {
        cout << "Generic template: " << data << endl;
    }
};

// Specialization for int
template <>
class MyClass<int> {
    int data;
public:
    MyClass(int val) : data(val) {}
    void display() {
        cout << "Specialized template for int: " << data << endl;
    }
};

// Specialization for char
template <>
class MyClass<char> {
    char data;
public:
    MyClass(char val) : data(val) {}
    void display() {
        cout << "Specialized template for char: '" << data << "'" << endl;
    }
};

int main() {
    MyClass<double> obj1(3.14);   // Uses the generic template
    MyClass<int> obj2(42);       // Uses the specialized template for int
    MyClass<char> obj3('A');     // Uses the specialized template for char

    obj1.display();  // Output: Generic template: 3.14
    obj2.display();  // Output: Specialized template for int: 42
    obj3.display();  // Output: Specialized template for char: 'A'

    return 0;
}
