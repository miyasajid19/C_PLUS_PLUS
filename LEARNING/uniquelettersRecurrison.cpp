#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
string unique( string str)
{
    if (str.length()==0)
    {
        return "";
    }
    char ch= str[0];
    string ans=unique(str.substr(1));
    if (ch==ans[0])
    {
        return ans;
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
    sort(str.begin(),str.end());
    cout<<"unique elements are : "<<endl<<unique(str);
    return EXIT_SUCCESS;
}