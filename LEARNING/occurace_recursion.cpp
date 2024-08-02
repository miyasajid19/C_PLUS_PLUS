#include <iostream>
#include <cstdlib>
using namespace std;
int firstoccurance(int arr[],int size,int i,int key)
{
    if(i==size)
    {
        return -1;
    }
    if (arr[i]==key)
    {
        return i;
    }
    return firstoccurance(arr,size,i+1,key);
}
int lastoccurance(int arr[], int size, int i, int key) {
    if (i == size) {
        return -1;
    }
    int restArray = lastoccurance(arr, size, i + 1, key);
    if (restArray != -1) {
        return restArray;
    }
    if (arr[i] == key) {
        return i;
    }
    return -1;
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int *arr=nullptr;
    int size;
    cout<<"enter the size of array : ";
    cin>>size;
    arr=new int[size]();
    for (int i=0;i<size;i++)
    {
        cout<<"element "<<i+1<<endl;
        cin>>arr[i];
    }
    cout<<"enter the key for gettting its occurance"<<endl;
    int key;
    cin>>key;
    cout<<"first occurance at "<<firstoccurance(arr,size,0,key)<<endl;
    cout<<"last occurance at "<<lastoccurance(arr,size,0,key)<<endl;

    return EXIT_SUCCESS;
}
