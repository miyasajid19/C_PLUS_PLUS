#include <iostream>
#include <cstdlib>
using namespace std;

long long merge(int arr[], int start, int mid, int stop)
{
    long long inv = 0;
    int n1 = mid - start + 1;  // Number of elements in the left subarray
    int n2 = stop - mid;       // Number of elements in the right subarray

    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
            inv += n1 - i;  // Count inversions
        }
    }

    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr[k++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;

    return inv;
}

long long mergeSort(int arr[], int start, int stop)
{
    long long inv = 0;
    if (start < stop)
    {
        int mid = (start + stop) / 2;
        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid + 1, stop);
        inv += merge(arr, start, mid, stop);
    }
    return inv;
}

int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << "How many data do you have? " << endl;
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl;
    cout << "Number of inversions: " << mergeSort(arr, 0, size - 1) << endl;

    delete[] arr;
    return EXIT_SUCCESS;
}
