#include <iostream>
#include<cstdlib>
using namespace std;
int calcualteGCDbyDivision(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    
    if(a>b)
    {
        swap(a,b);
    }
    return calcualteGCDbyDivision(a,b%a);
}
int calcualteGCDbyDifference(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    
    if(a>b)
    {
        swap(a,b);
    }
    return calcualteGCDbyDifference(a,b-a);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
int a,b;
cout<<"enter the first number : "<<endl;
cin>>a;
cout<<"enter the first number : "<<endl;
cin>>b;
cout<<"The HCF/GCD is "<<calcualteGCDbyDifference( a,b)<<"  calculated by euclid's differene algorithm"<<endl;
cout<<"The HCF/GCD is "<<calcualteGCDbyDivision( a,b)<<"  calcualted by euclid's division algorithm"<<endl;
    return EXIT_SUCCESS;
}