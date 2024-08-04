#include <iostream>
using namespace std;
void merge(int arr[],int start, int middle,int last)
{
    int n1=middle-start+1;
    int n2=last-middle;
    int arr1[n1];
    int arr2[n2];
    for (int i =0;i<n1;i++)
    {
        arr1[i]=arr[start+i];
    }
    for (int i =0;i<n2;i++)
    {
        arr2[i]=arr[middle+1+i];
    }
    int ptr1=0,ptr2=0,k=start;
    while(ptr1<n1 and ptr2<n2)
    {
        if (arr1[ptr1]<arr2[ptr2])
        {
            arr[k++]=arr1[ptr1++];
        }
        else
        {
            arr[k++]=arr2[ptr2++];
        }
    }
    while(ptr1<n1)
    {
           arr[k++]=arr1[ptr1++];
    }
    while(ptr2<n2)
    {
           arr[k++]=arr2[ptr2++];
    }
}
void mergeSort(int arr[], int start, int last)
{
    if (start < last)
    {
        int middle = (start + last) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, last);
        merge(arr,start,middle,last);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << "how many data do you have ?  " << endl;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << endl;
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"sorted array using merge sort : "<<endl;
    for (int i = 0; i < n; i++)
    {

        cout<<arr[i]<<" ";
    }

    return 0;
}
