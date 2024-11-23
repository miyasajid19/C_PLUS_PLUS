#include <iostream>
#include <cstdlib>
using namespace std;
class divide
{
    int a;
    int b;

public:
    divide()
    {
        this->a = this->b = 0;
    }
    divide(int a)
    {
        this->a = a;
        this->b = 0;
    }
    divide(int a, int b) : a(a), b(b) {}
    int result()
    {
        if (a == 0 and b == 0)
            throw "indeterminant form";
        if (b == 0)
            throw "division by zero";

        return a / b;
        throw "unexpected error";
    }
};
int main()
{
    divide a;
    try
    {
        cout << a.result();
    }
    catch (const char *e)
    {
        cerr << e << '\n';
    }
    divide b(432);
    try
    {
        cout << b.result();
    }
    catch (const char *e)
    {
        cerr << e << '\n';
    }

    divide c(432, 407);
    try
    {
        cout << c.result() << endl;
    }
    catch (const char *e)
    {
        cerr << e << '\n';
    }
    try
    {
        c.result();//this will result
        a.result();//this will execute but throws error
        b.result();//control will never come back here and not get executed
    }
    catch (const char *e)
    {
        cerr << e<< '\n';
    }

    return EXIT_SUCCESS;
}