#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        cout << "Base class display" << endl;
    }
    virtual void print() {
        cout << "Base class print" << endl;
    }
    void baseFunction() {
        cout << "Base class specific function" << endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display" << endl;
    }
    void print() override {
        cout << "Derived class print" << endl;
    }
    void derivedFunction() {
        cout << "Derived class specific function" << endl;
    }
};

int main() {
    Base* basePtr; // Base class pointer

    Derived derivedObj;
    basePtr = &derivedObj; // Base class pointer pointing to derived class object

    basePtr->display();         // Calls Derived's display (runtime polymorphism)
    basePtr->print();           // Calls Derived's print (runtime polymorphism)
    basePtr->baseFunction();    // Calls Base's baseFunction (compile-time binding)

    // basePtr->derivedFunction(); // ERROR: Base class pointer cannot access derivedFunction

    // To access derivedFunction, you need to explicitly cast the pointer to Derived type
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->derivedFunction(); // Now accessible

    return 0;
}
