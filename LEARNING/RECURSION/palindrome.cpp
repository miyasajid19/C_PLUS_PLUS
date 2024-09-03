#include <iostream>
#include <cstdlib>
using namespace std;
bool checkPalindrome(int num, int * temp)
{

    if (num < 10)
    {
        int last=(*temp)%10;
    (*temp)/=10;
    return num==last;
    }
        bool result=checkPalindrome(num/10,temp) and (num%10==(*temp)%10);
    (*temp)/=10;
        return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int num;
    cout<<"enter the number  to check :: "<<endl;
    cin>>num;
    cout << boolalpha;
    int temp = num;
    cout << checkPalindrome(num, &temp);
    return EXIT_SUCCESS;
}