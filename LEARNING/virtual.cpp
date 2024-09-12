#include <iostream>
#include <cstdlib>
using namespace std;

// Base class A
class A
{
public:
    int a;  // Attribute of class A

    // Method to set the value of 'a'
    void set(int a)
    {
        this->a = a;  // Using 'this' pointer to avoid ambiguity with parameter 'a'
    }

    // Method to get the value of 'a'
    int get()
    {
        return this->a;  // Returning the value of 'a'
    }
};

// Class B inherits from A virtually
class B : public virtual A
{
    int b;  // Attribute of class B
};

// Class C inherits from A virtually
class C : public virtual A
{
    int c;  // Attribute of class C
};

// Class D inherits from both B and C
class D : public B, public C
{
    int d;  // Attribute of class D
};

int main()
{
    // Code for competitive programming environments (not used here)
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Printing the purpose of the program
    cout << "Demonstrating virtual inheritance in C++" << endl;
    cout << "Avoiding ambiguity in multiple inheritance scenarios." << endl;

    // Creating an object of class D
    D d;

    // Demonstrating that virtual inheritance resolves ambiguity
    // Without virtual inheritance, there would be two copies of 'a' in class D.
    cout << "\nAttempting to set the value of 'a' through class D..." << endl;

    // Setting value of 'a' through object of class D
    d.set(432);

    // Retrieving and displaying the value of 'a' through object of class D
    cout << "The value of 'a' after calling d.set(432): " << d.get() << endl;

    // Explanation of what would happen without virtual inheritance
    cout << "\nExplanation:\n";
    cout << "Without using virtual inheritance, class D would inherit two separate copies\n";
    cout << "of class A: one from class B and another from class C, leading to ambiguity\n";
    cout << "when trying to access 'a'. By using virtual inheritance, class D inherits\n";
    cout << "only one shared copy of class A, thus resolving the ambiguity." << endl;

    return EXIT_SUCCESS;
}
