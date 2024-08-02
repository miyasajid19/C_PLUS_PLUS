#include<iostream>
#include<cstdlib>
using  namespace std;
int binarysearch(int arr[],int size,int key)
{
    int first =0, last=size-1;
    int middle=(first+last)/2;
    while(first<=last)
    {
        if(arr[middle]==key)
        {
            return middle;
        }
        else if (arr[middle]>key)
        {
            last=middle-1;
        }
        else
        {
            first=middle+1;
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
    cout<<binarysearch(arr,size,key);
    return EXIT_SUCCESS;
}