// Given a number n.
// Find the sum of natural numbers till n but with alternate signs.
// That means if n = 5 then you have to return 1-2+3-4+5 = 3 as your answer.
// Constraints: 0<=n<=1e6
// Inputl: n = 10 Output 1:-5
// Input2 : n = 5
// Output2: 3
#include <iostream>
#include<cstdlib>
using namespace std;
int alternateSum(int num)
{   
    if(num==0)
    {
        return 0;
    }
    if(num%2==0)
    {
        return -num+alternateSum(num-1);
    }
    else{
        return num+alternateSum(num-1);

    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
int n;
cout<<"enter the value of n"<<endl;
cin>>n;

cout<<"the resultant alternate sum  is "<<alternateSum(n);
    return EXIT_SUCCESS;
}

