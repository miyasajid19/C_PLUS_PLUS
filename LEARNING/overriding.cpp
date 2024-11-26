#include <iostream>
#include <cstdlib>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function to simulate an animal's sound
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }

    // Virtual function to simulate animal behavior
    virtual void move() {
        cout << "The animal is moving" << endl;
    }
};

// Derived class 1: Dog
class Dog : public Animal {
public:
    // Override makeSound for Dog
    void makeSound() override {
        cout << "The dog barks: Woof Woof!" << endl;
    }

    // Override move for Dog
    void move() override {
        cout << "The dog is running" << endl;
    }
};

// Derived class 2: Cat
class Cat : public Animal {
public:
    // Override makeSound for Cat
    void makeSound() override {
        cout << "The cat meows: Meow Meow!" << endl;
    }

    // Override move for Cat
    void move() override {
        cout << "The cat is walking gracefully" << endl;
    }
};

int main() {
    // Create a Dog object
    Dog dog;
    dog.makeSound();  // Calls Dog's version of makeSound
    dog.move();       // Calls Dog's version of move

    // Create a Cat object
    Cat cat;
    cat.makeSound();  // Calls Cat's version of makeSound
    cat.move();       // Calls Cat's version of move

    // Using a pointer of type Animal to refer to a Dog object
    Animal* ptr = new Dog();
    ptr->makeSound();  // Calls Dog's version of makeSound (polymorphism)
    ptr->move();       // Calls Dog's version of move (polymorphism)

    // Now using the pointer to refer to a Cat object
    ptr = new Cat();
    ptr->makeSound();  // Calls Cat's version of makeSound (polymorphism)
    ptr->move();       // Calls Cat's version of move (polymorphism)

    // Clean up dynamic memory allocation
    delete ptr;

    return EXIT_SUCCESS;
}
