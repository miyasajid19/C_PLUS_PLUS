#include <iostream>
#include <cstdlib>
#include <stdexcept> // For runtime_error
using namespace std;

class Divide {
private:
    int a, b;

public:
    Divide() : a(0), b(0) {}
    Divide(int a) : a(a), b(0) {}
    Divide(int a, int b) : a(a), b(b) {}
    ~Divide() {}

    int result() {
        if (a == 0 && b == 0)
            throw runtime_error("Indeterminant form: both numerator and denominator are zero.");
        if (b == 0)
            throw runtime_error("DivisionByZeroError: denominator is zero.");
        return a / b;
    }
};

int main() {
    Divide a;
    Divide b(407);
    Divide c(432, 407);

    // First operation
    try {
        cout << a.result() << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    // Second operation
    try {
        cout << b.result() << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    // Third operation
    try {
        cout << c.result() << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    // Combined operations
    try {
        cout << c.result() << endl; // This will succeed
        cout << b.result() << endl; // This will throw
        cout << a.result() << endl; // Won't execute
    } catch (const runtime_error& e) {
        cerr << "Runtime Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Standard Exception: " << e.what() << endl;
    } catch (const char* e) {
        cerr << "Char Pointer Exception: " << e << endl;
    } catch (...) {
        cerr << "Unexpected error occurred!" << endl;
    }

    return EXIT_SUCCESS;
}
