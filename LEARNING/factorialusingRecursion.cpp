#include <iostream>
#include <cstdlib>
using namespace std;
long  long fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int num;
    cout << "enter the number to calculate the factorial : ";
    cin >> num;
    cout<<"The factorial of "<<num<<" is "<<fact(num);
    return EXIT_SUCCESS;
}
