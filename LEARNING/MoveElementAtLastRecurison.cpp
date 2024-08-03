#include<iostream>
#include<cstdlib>
using namespace std;
string movech( string str,char key)
{
    if (str.length()==0)
    {
        return "";
    }
    char ch= str[0];
    string ans=movech(str.substr(1),key);
    if (ch==key)
    {
        return ans+ch;
    }
    return ch+ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cout<<"enter any string"<<endl;
    string str;
    getline(cin,str);
    cout<<"enter the element that you want to put at last"<<endl;
    char ch;
    cin>>ch;
    cout<<"the result is :"<<endl;
    cout<<movech(str,ch);
    return EXIT_SUCCESS;
}