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
    cout<<"Enter the size of array";
    cin>>size;
    int arr[size];
    for (int i =0;i<size;i++)
    {
        cout<<"ELement "<<i+1<<endl;
        cin>>arr[i];
    }
    for (int i =0;i<size;i++)
    {
        for (int j=i;j<size;j++)
        {
            for (int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" " ;               
            }
            cout<<endl;
        }
    }
    return EXIT_SUCCESS;
}