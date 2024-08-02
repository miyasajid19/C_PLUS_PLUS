#include<iostream>
#include<cstdlib>
using namespace std;
int howmany(int number,int divisor1,int divisor2)
{
    return ((number/divisor1)+(number/divisor2)-(number/(divisor1*divisor2)));
}
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int number,divisor1,divisor2;
    cout<<"enter number, divisor 1,divisor 2";
    cin>>number>>divisor1>>divisor2;
    cout<<"there are " << howmany(number,divisor1,divisor2)<<" numbers which are divisble by "<< divisor1 <<" or "<<divisor2<<endl; 
    return EXIT_SUCCESS;
}