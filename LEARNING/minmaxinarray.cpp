#include<iostream>
#include<cstdlib>
using  namespace std;
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int arr[10];
    for(int i=0;i<10;i++)
    {
        cout<<"Enter the element "<<i+1<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<"The minimum and maximum values in the array are "<<arr[0]<<" and " <<arr[9]<<"respctively";
    return EXIT_SUCCESS;
}