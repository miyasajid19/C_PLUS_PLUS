#include<iostream>
#include<cstdlib>
using namespace std;
int calculate(int n)
{
    return n*(n+1)/2;
}
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"enter n"<<endl;
    int n;
    cin>>n;
    cout<<"the sum of first "<<n<<" nartural number are "<< calculate(n);
    return EXIT_SUCCESS;
}