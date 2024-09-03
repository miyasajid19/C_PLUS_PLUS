#include <iostream>
#include <cstdlib>
#include <cmath>
#include<string>
using namespace std;
string bitEquivalent(int num)
{
    string str="";
    while(num!=0)
    {
        int bit=num|0;
        char bits=bit+'0';
        str+=bits;
    }
    return str;
}
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int num;
    cout << "enter any number" << endl;
    cin >> num;
    int ans = 0;
    int i=0;
    while(num!=0)
    {
        int bit= num&1;
        ans=ans+bit*pow(10,i);
        num=num>>1;
        i++;
    }
    cout<<"bit equivalent is "<<ans;
    cout<<endl<<bitEquivalent(num);
    return EXIT_SUCCESS;
}