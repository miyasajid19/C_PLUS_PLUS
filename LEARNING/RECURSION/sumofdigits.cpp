#include <iostream>
#include<cstdlib>
using namespace std;
int sumOfDigits(int a)
{
     if (a==0)
     {
        return 0;
     }
     return a%10+sumOfDigits(a/10);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
cout<<"enter any number : "<<endl;
int a;
cin>>a;
cout<<sumOfDigits(a);
    return EXIT_SUCCESS;
}