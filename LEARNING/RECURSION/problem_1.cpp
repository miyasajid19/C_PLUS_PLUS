// Given a number n. Find the increasing sequence from 1 to n without using any loop. 
// Constraint: 0<n<=le6
//  Inputl: n = 4 Output 1:1234 Input2 : n = 2 Output2:12
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