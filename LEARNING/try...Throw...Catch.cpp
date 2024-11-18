#include <iostream>
#include <cstdlib>
using namespace std;

float divide(int a, int b)
{
    cout<<"i had just enterred the function"<<endl;
    if (a == 0 && b == 0)
        throw "indeterminant"; // Throwing a string literal
    else if (b == 0)
        throw 0; // Throwing an integer
    
    cout<<"i am leaving try function"<<endl;
    return static_cast<float>(a) / b;
}

int main()
{
    try
    {
        cout << divide(432, 407)<<endl;
        cout << divide(0, 0);
        cout << divide(321, 0); // control will not come here after raiseing error
    }
    catch (char const *msg) // Catching string literal exceptions
    {
        cout << "Error: " << msg << endl;
    }
    catch (int) // Catching integer exception (indicating division by zero)
    {
        cout << "Error: Division by zero." << endl;
    }
    catch (const exception &e) // Catching standard exceptions (if any)
    {
        cout << e.what() << '\n';
    }
    cout<<"i am exiting"<<endl;
    return EXIT_SUCCESS;
}
