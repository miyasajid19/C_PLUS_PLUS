#include <iostream>
#include <cstdlib>
using namespace std;

bool sorted(int arr[], int size)
{
    if (size == 1)
    {
        return true;
    }
    bool issorted = sorted(arr + 1, size - 1);
    return ((arr[0] <= arr[1]) and issorted);
}
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    int *arr = nullptr;
    cout << "enter the size of array : ";
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "enter element " << i + 1 << endl;
        cin >> arr[i];
    }
    if (sorted(arr, size))
    {
        cout << "array is sorted";
    }
    else
    {
        cout << "array is not sorted";
    }
    return EXIT_SUCCESS;
}
