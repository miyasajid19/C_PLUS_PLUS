#include <iostream>
#include<cstdlib>
using namespace std;
int factorial(int a)
{
    if (a==0)
    {
        return 1;
    }
    else if (a==1)
    {
        return 1;
    }
    else{
        return a* factorial(a-1);
    }
    
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=20;
    for ( int i =0;i<n;i++){
        for (int j=0;j<=i;j++)
        {
            cout<<factorial(i)/(factorial(i-j)*factorial(j));
            cout<<" ";
        }
        cout<<endl;
    }
}