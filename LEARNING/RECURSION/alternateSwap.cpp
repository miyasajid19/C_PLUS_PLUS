#include <iostream>
#include <cstdlib>
using namespace std;
void alternateSwap(int *arr, int i, int size)
{
    if (i >= size - 1)
    {
        return;
    }
    swap(arr[i], arr[i + 1]);
    alternateSwap(arr, i + 2, size);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int size;
    cout << "enter the size of array :: ";
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"A["<<i<<"] :::: ";
        cin>>arr[i];
    }   
    alternateSwap(arr, 0, size);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return EXIT_SUCCESS;
}   