#include <iostream>
#include<cstdlib>
using namespace std;
int power(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    return a *power(a,b-1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
int a,b;
cout<<"enter a and b"<<endl;
cin>>a>>b;
cout<<a<<" power "<<b<<" is ";
cout<<power(a,b);
    return EXIT_SUCCESS;
}