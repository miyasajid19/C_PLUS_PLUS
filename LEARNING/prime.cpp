#include<iostream>
using namespace std;
bool check(int n)
{int a;
    for ( a=2;a<n;a++)
    {
        if (n%a==0)
        {
            return false;
        }
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"enter the lower limit"<<endl;
    int lowerlmt,upperlmt;
    cin>>lowerlmt;
    cout<<"enter the upper limit"<<endl;
    cin>>upperlmt;
    if (upperlmt<lowerlmt)
    {
        int temp=lowerlmt;
        lowerlmt=upperlmt;
        upperlmt=temp;
    }    
    for (int i = lowerlmt;i<=upperlmt;i++)
    {
        if (check(i))
        {
            cout<<i<<"\t";
        }
    }
    return 0;
}