#include<iostream>
#include<cstdlib>
using  namespace std;
int linearsearch(int arr[],int size,int key)
{
    for (int i =0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
        
    }
    return -1;
}
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int size;
    cout<<"enter the size of array "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element "<<i+1<<endl;
        cin>>arr[i];
    }
    //bubble sorting
    for (int i =0;i<size;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"enter the element to search "<<endl;
    int key;
    cin>>key;
    cout<<linearsearch(arr,size,key);
    return EXIT_SUCCESS;
}