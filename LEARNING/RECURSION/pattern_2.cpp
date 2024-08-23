// Given a number num and a value k. Print k multiples of num.
// Constraints: k > 0
// Input 1: num = 12, k = 5
// Output 1: 12,24,36,48,60
// Input 2: num = 3, k = 8
// Output 2:3,6,9,12,15,18,21, 24.
#include <iostream>
#include <cstdlib>
using namespace std;
void multiple(int num, int k)
{
    if (k == 0)
    {
        return;
    }
    multiple(num, k - 1);
    cout << num * k << " ";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int num, k;
    cout << "enter any number" << endl;
    cin >> num;
    cout << "enter the value of K : " << endl;
    cin >> k;
    multiple(num, k);
    return EXIT_SUCCESS;
}