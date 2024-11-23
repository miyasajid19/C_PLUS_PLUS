#include <iostream>
using namespace std;

// Template class definition
template <typename T>
class Box {
private:
    T value;  // variable of type T

public:
    // Constructor
    Box(T val) : value(val) {}

    // Function to set the value
    void setValue(T val) {
        value = val;
    }

    // Function to get the value
    T getValue() {
        return value;
    }

    // Function to display the value
    void displayValue() {
        cout << "The value is: " << value << endl;
    }
};

int main() {
    // Creating an object of type int
    Box<int> intBox(10);
    intBox.displayValue(); // Output: The value is: 10
    intBox.setValue(20);
    intBox.displayValue(); // Output: The value is: 20

    // Creating an object of type double
    Box<double> doubleBox(5.5);
    doubleBox.displayValue(); // Output: The value is: 5.5
    doubleBox.setValue(10.25);
    doubleBox.displayValue(); // Output: The value is: 10.25

    // Creating an object of type string
    Box<string> stringBox("Hello");
    stringBox.displayValue(); // Output: The value is: Hello
    stringBox.setValue("World");
    stringBox.displayValue(); // Output: The value is: World

    return 0;
}
