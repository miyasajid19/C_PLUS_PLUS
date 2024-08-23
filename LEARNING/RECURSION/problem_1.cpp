// 
#include <iostream>
#include<cstdlib>
using namespace std;
void pattern(int n)
{
    if(n==1)
    {
        cout<<1<<" ";
        return;
    }
        pattern(n-1);
        cout<<n<<" ";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
pattern(5);
    return EXIT_SUCCESS;
}