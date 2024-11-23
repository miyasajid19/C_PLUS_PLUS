#include <iostream>
#include <cstdlib>
#include <stdexcept> // For exception handling
using namespace std;

int main()
{
    // Handle memory allocation errors
    try
    {
        // Large allocation to simulate failure
        int *arr = new int[1000000000]; // Adjust size to test
        delete[] arr;                   // Free memory if allocation succeeds
    }
    catch (const bad_alloc &e)
    {
        cerr << "Memory allocation error: " << e.what() << '\n';
    }

    // Array for out-of-bounds access
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    // Handle out-of-bounds access
    try
    {
        int index = 11; // Example of invalid index
        if (index < 0 || index >= 10)
            throw out_of_range("Array index out of bounds");
        cout << "Value at index " << index << ": " << arr[index] << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Out-of-bounds error: " << e.what() << '\n';
    }

    // Handle negative indexing error
    try
    {
        int index = -1; // Example of invalid index
        if (index < 0)
            throw invalid_argument("Negative array index is not allowed");
        cout << "Value at index " << index << ": " << arr[index] << endl;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Invalid index error: " << e.what() << '\n';
    }

    // Catch any other unexpected exceptions
    try
    {
        // Code that might throw unexpected exceptions
        throw runtime_error("Unexpected runtime error");
    }
    catch (const exception &e)
    {
        cerr << "Unhandled exception: " << e.what() << '\n';
    }
    catch (...)
    {
        cerr << "An unknown error occurred." << '\n';
    }

    return EXIT_SUCCESS;
}
