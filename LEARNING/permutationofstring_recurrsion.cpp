#include<iostream>
#include<cstdlib>
using namespace std;
void permution(string str,string ans)
{
    if (str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    for (int i =0;i<str.length();i++)
    {
        char ch=str[i];
        string remaining=str.substr(0,i)+str.substr(i+1);
        permution(remaining,ans+ch);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string str;
    cout<<"enter the string : "<<endl;
    cin>>str;
    permution(str,"");    
    return EXIT_SUCCESS;
}