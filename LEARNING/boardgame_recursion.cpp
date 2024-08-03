#include<iostream>
#include<cstdlib>
using namespace std;
int countpath(int start, int end)
{
    if (start==end)
    {
        return 1;
    }
    if (start>end)
    {
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++)
    {
        count+=countpath(start+i,end);
    }
    return count;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif    
    cout<<"enter the starting point"<<endl;
    int start;
    cin>>start;
    cout<<"enter the ending point"<<endl;
    int end;
    cin>>end;
    cout<<"there are "<<countpath(start,end)<<" path possible  to move from "<<start<<" and "<<end<<endl;
    return EXIT_SUCCESS;
}