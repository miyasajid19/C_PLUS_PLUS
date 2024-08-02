#include <iostream>
#include <cstdlib>
using namespace std;
void reverse(string str)
{
    if (str.length()==0)
    {
        return;
    }
    string reststr=str.substr(1);
    reverse(reststr);
    cout<<str[0];
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str;
    cout<<"enter the string"<<endl;
    getline(cin,str);
    reverse(str);
    return EXIT_SUCCESS;
}
