#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    // Handling memory allocation failure
    try
    {
        int* arr = new int[10000000000000]; // Attempt to allocate a large array
        delete[] arr; // Free allocated memory
    }
    catch (const bad_alloc &e)
    {
        cerr << "Memory allocation failed: " << e.what() << '\n';
    }

    // Using std::vector for bounds checking
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    try
    {
        cout << "Element at index 11: " << arr.at(11) << endl; // Throws out_of_range
    }
    catch (const out_of_range &e)
    {
        cerr << "Out of range error: " << e.what() << '\n';
    }

    try
    {
        cout << "Element at index -1: " << arr.at(-1) << endl; // Throws out_of_range
    }
    catch (const out_of_range &e)
    {
        cerr << "Out of range error: " << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}
