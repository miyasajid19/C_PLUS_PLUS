#include <iostream>
#include<cstdlib>
using namespace std;
void Traverse(int arr[],int index, int size)
{
    if(index<0 or index>=size)
    {
        return;
    }
    cout<<arr[index]<<" ";
    Traverse(arr,++index,size);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
int arr[]={1,2,3,4,5,6,7,8,9,0};
Traverse(arr,0,10);
    return EXIT_SUCCESS;
}