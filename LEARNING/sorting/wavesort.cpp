#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[], int size)
{
    for (int i = 1; i < size; i += 2)
    {
        // Ensure the current element is greater than the previous element
        if (i > 0 && arr[i] < arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        
        // Ensure the current element is greater than the next element
        if (i < size - 1 && arr[i] < arr[i + 1])
        {
            swap(arr, i, i + 1);
        }
    }
}

int main()
{
#ifndef JUDGE_ONLINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
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

    waveSort(arr, size);

    cout << "\nSorted array in wave form: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return EXIT_SUCCESS;
}
