#include <iostream>
using namespace std;
void swap(int arr[], int start, int last)
{
    int temp = arr[start];
    arr[start] = arr[last];
    arr[last] = temp;
}
int partition(int arr[], int start, int last)
{
    int pivot = arr[last];
    int i = start - 1;
    for (int j = start; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, last);
    return i + 1;
}
void QuickSort(int arr[], int start, int last)
{
    if (start < last)
    {
        int pi = partition(arr, start, last);
        QuickSort(arr, start, pi - 1);
        QuickSort(arr, pi + 1, last);
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
    QuickSort(arr,0,n-1);
    cout << "sorted array using merge sort : " << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}
