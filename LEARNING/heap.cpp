#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void swap(int *ptr1, int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int* p=new int();
    *p=432;
    cout<<*p<<endl;
    delete(p);
    //allocating array
    cout<<"How many number do you want to store ?"<<endl;
    int num;
    cin>>num;
    int *arr=new int[num];
    for (int i =0;i<num;i++)
    {
        cout<<"enter the element "<<i+1<<endl;
        cin>>arr[i];
    }
    for (int i =0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
    delete[]arr;
    arr=NULL;
    
    return EXIT_SUCCESS;
}
