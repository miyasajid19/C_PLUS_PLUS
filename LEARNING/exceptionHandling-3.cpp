#include <iostream>
#include <cstdlib>
using namespace std;

class Divide
{
    int a, b;

public:
    Divide() : a(0), b(0) {}
    Divide(int a) : a(a), b(0) {}
    Divide(int a, int b) : a(a), b(b) {}

    int result()
    {
        if (a == 0 && b == 0)
            throw 400; // Indeterminate form
        if (b == 0)
            throw 404; // Division by zero
        return a / b;
    }
};

int main()
{
    Divide a;
    Divide b(432);
    Divide c(432, 407);

    try
    {
        cout << "Result of a: " << a.result() << endl;
    }
    catch (int x)
    {
        cerr << (x == 400 ? "Bad Request: Indeterminate form" : "Division by zero error") << endl;
    }

    try
    {
        cout << "Result of b: " << b.result() << endl;
    }
    catch (int x)
    {
        cerr << (x == 400 ? "Bad Request: Indeterminate form" : "Division by zero error") << endl;
    }

    try
    {
        cout << "Result of c: " << c.result() << endl;
    }
    catch (int x)
    {
        cerr << (x == 400 ? "Bad Request: Indeterminate form" : "Division by zero error") << endl;
    }

    try
    {
        cout << "Combined results:" << endl;
        cout << "c: " << c.result() << endl; // This will succeed
        cout << "b: " << b.result() << endl; // This will throw
        cout << "a: " << a.result() << endl; // This won't execute
    }
    catch (int x)
    {
        cerr << (x == 400 ? "Bad Request: Indeterminate form" : "Division by zero error") << endl;
    }

    return EXIT_SUCCESS;
}