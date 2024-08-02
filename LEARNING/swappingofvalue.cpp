#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a = 432, b = 407;
    int *ptr1 = &a, *ptr2 = &b;
    cout << a << " " << b << endl;
    swap(ptr1, ptr2);
    cout << a << " " << b << endl;
    return EXIT_SUCCESS;
}
