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
    cout<<"enter the size of array : "<<endl;
    cin>>size;
    int arr[size+1];
    arr[size]=-1;
    int count =0;
    for (int i =0;i<size;i++)
    {
        cout<<"Enter the element "<< i+1<<endl;
        cin>>arr[i];
    }
    if (size==1){
        cout<<"The no of record breaking day is 1"<<endl;
    }
    for (int i =1;i<size;i++)
    {
        if ((arr[i]>arr[i-1])&&(arr[i]>arr[i+1]))
        {
            count+=1;
        }
    }
    cout<<"the no. of record breaking days are "<<count;
    return EXIT_SUCCESS;
}