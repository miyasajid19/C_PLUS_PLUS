#include<iostream>
#include<cstdlib>
using namespace std;
void replace(string str)
{
    if (str.length()==0)
    {
        return;
    }
    if (((str[0]=='p') and (str[1]=='i')))
    {
        cout<<"3.14";
        replace(str.substr(2));
    }
    else{
        cout<<str[0];
        replace(str.substr(1));
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string str;
    getline(cin,str);
    replace(str);
    return EXIT_SUCCESS;
}