#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int size;
    cout<<"enter the size of array : ";
    cin>>size;
    int arr[size];
    for(int i =0;i<size;i++)
    {
        cout<<"Enter the element "<<i+1<<endl;
        cin>>arr[i];
    }
    int commondiffernce=arr[1]-arr[0];
    int ans=2;
    int current =2;
    int i=2;
    while( i <size)
    {
        if ((arr[i]-arr[i-1])==commondiffernce)
        {
            current+=1;
        }
        else{
            commondiffernce=arr[i]-arr[i-1];
            current=2;
        }
        ans=max(ans,current);
        i++;
    }
    cout<<ans;
    return EXIT_SUCCESS;
}