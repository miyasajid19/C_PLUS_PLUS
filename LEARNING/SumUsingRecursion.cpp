#include<iostream>
#include<cstdlib>
using namespace std;
int sum(int n)
{
    if (n==1)
    {
        return 1;
    }
    return n+sum(n-1);
}

int main() {
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    cout<<"the sum of first "<<n<<" natural numbers is "<<sum(n);
    return EXIT_SUCCESS;
}
