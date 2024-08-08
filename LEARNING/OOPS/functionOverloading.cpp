#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class FunLoading
{
public:
    void sum(int a, int b)
    {
        cout << a << " + " << b << " = " << a + b << endl;
    }

    void sum(float a, float b)
    {
        cout << a << " + " << b << " = " << a + b << endl;
    }

    void sum(double a, double b)
    {
        cout << a << " + " << b << " = " << a + b << endl;
    }

    void sum(int a, int b, int c)
    {
        cout << a << " + " << b << " + " << c << " = " << a + b + c << endl;
    }

    void sum(float a, float b, float c)
    {
        cout << a << " + " << b << " + " << c << " = " << a + b + c << endl;
    }

    void sum(double a, double b, double c)
    {
        cout << a << " + " << b << " + " << c << " = " << a + b + c << endl;
    }

    void sum(string a, string b)
    {
        cout << a << " + " << b << " = " << a + b << endl;
    }

    void sum(string a, string b, string c)
    {
        cout << a << " + " << b << " + " << c << " = " << a + b + c << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    FunLoading c;
    c.sum(1, 2);
    c.sum(432.1, 234.1); // Now calls the double version
    c.sum("Obito", "Uchiha");
    c.sum(1, 2, 3);
    c.sum(432.1, 234.1, 123.432); // Now calls the double version
    c.sum("Obito", "Uchiha", "Tobi");
    return EXIT_SUCCESS;
}
