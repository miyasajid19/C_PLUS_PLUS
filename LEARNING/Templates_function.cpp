#include <iostream>
#include <cstdlib>
#include <string>  // for std::to_string

using namespace std;

template<typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(432, 407) << endl;            // Add two integers
    cout << add(432.407, 407.432) << endl; 
    return EXIT_SUCCESS;
}
