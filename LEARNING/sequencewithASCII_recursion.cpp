#include<iostream>
#include<cstdlib>
using namespace std;
void possiblesubstring(string str,string ans)
{
    if (str.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=str[0];
    int code=ch;
    string remaining=str.substr(1);
    possiblesubstring(remaining,ans);
    possiblesubstring(remaining,ans+ch);
    possiblesubstring(remaining,ans+to_string(ch));
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"enter string"<<endl;
    string str;
    cin>>str;
    cout<<"possiible substrings are : "<< endl;
    possiblesubstring(str,"");
    return EXIT_SUCCESS;
}