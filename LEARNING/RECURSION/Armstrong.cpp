#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int no_of_digits(int num)
{
    int index = 0;
    while (num)
    {
        ++index;
        num /= 10;
    }
    return index;
}
int Armstrong(int number, int index)
{
    if (number == 0)
    {
        return 0;
    }
    return pow(number % 10, index) + Armstrong(number / 10, index);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int number;
    cout << "enter the number to check for Armstrong ::: " << endl;
    cin >> number;
    if (number == Armstrong(number, no_of_digits(number)))
    {
        cout << number << " is an armstrong number" << endl;
    }
    else
    {

        cout << number << " is an not armstrong number" << endl;
    }
    return EXIT_SUCCESS;
}