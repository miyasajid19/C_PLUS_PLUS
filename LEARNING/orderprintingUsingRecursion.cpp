#include <iostream>
#include <cstdlib>
using namespace std;
void decreasing(int n)
{
    if (n==0)
    {
        return;
    }
    cout<<n<<" ";
    decreasing(n-1);
}
void increasing(int n)
{
    if (n==0)
    {
        return;
    }
    increasing(n-1);
    cout<<n<<" ";
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "enter the upper bound"<<endl;
    int num;
    cin >> num;
    decreasing(num);
    cout<<endl;
    increasing(num);
    return EXIT_SUCCESS;
}
