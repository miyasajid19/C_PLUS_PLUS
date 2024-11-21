#include <iostream>

class MyClass {
private:
    static int objectCount;  // Static member to keep track of object count

public:
    // Constructor
    MyClass() {
        objectCount++;  // Increment the count when a new object is created
    }

    // Destructor
    ~MyClass() {
        objectCount--;  // Decrement the count when an object is destroyed
    }

    // Static function to return the current object count
    static int getObjectCount() {
        return objectCount;
    }
};

// Initialize the static member outside the class
int MyClass::objectCount = 0;

int main() {
    MyClass obj1;
    MyClass obj2;

    std::cout << "Number of objects created: " << MyClass::getObjectCount() << std::endl;

    {
        MyClass obj3;
        std::cout << "Number of objects created: " << MyClass::getObjectCount() << std::endl;
    } // obj3 goes out of scope and is destroyed

    std::cout << "Number of objects created: " << MyClass::getObjectCount() << std::endl;

    return 0;
}
