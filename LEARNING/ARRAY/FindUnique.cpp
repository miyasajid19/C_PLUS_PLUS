#include <iostream>
#include <cstdlib>
using namespace std;
int Unique(int * arr, int size)
{
    int ans=0;
    for(int i =0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int arr[] = {3,1,2,3,2,1,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Unique :: " << Unique(arr, size);
    return EXIT_SUCCESS;
}
/*
There are some array given
such that other elements are
present twice and
 there is one element which
 occurs only onetimes
*/