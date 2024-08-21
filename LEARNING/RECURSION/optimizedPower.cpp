#include <iostream>
#include<cstdlib>
using namespace std;
int power(int a, int b)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        int result=power(a,b/2);
        return result*result;
    }
    else{
        int result=power(a,(b-1)/2);
        return a * result*result;
    }
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
// it has log q time complexity