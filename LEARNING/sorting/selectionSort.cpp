#include <iostream>
#include <cstdlib>
using namespace std;
void sortByMinimum(int *arr, int size)
{
    int minimumindex, j;
    for (int i = 0; i < size; i++)
    {
        minimumindex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[minimumindex] > arr[j])
            {
                minimumindex = j;
            }
        }
        if (minimumindex != j)
        {
            swap(arr[minimumindex], arr[i]);
        }
    }
}
void sortByMaximum(int *arr, int size)
{
    int minimumindex, j;
    for (int i = size - 1; i >= 0; i--)
    {
        minimumindex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[minimumindex] > arr[j])
            {
                minimumindex = j;
            }
        }
        if (minimumindex != j)
        {
            swap(arr[minimumindex], arr[i]);
        }
    }
}

int main()
{
    int arr[] = {4, 2, 5, 3, 63, 6, 35, 32, 63, 23};
    int size;
    size = sizeof(arr) / sizeof(arr[0]);
    cout << "unsorted array ::: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // swapping by placing the minimum element first
    sortByMaximum(arr, size);
    cout << "sorted array::" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr1[] = {5, 3, 2, 5, 7, 3, 3, 2, 9, 1, 3, 1, 3, 4, 5, 2};
    size = sizeof(arr1) / sizeof(arr1[0]);
    cout << "unsorted array 1 ::: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    sortByMinimum(arr1, size);
    // swapping by fixing the maximum element first
    cout << "sorted array 1 ::::" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}



/*
intutions:
    repeatedly find the minimum or maximum elements and placed it in first or last of "unsorted array"
stability:
    it is unstable sorting algorithm
time complexity :: O(n^2)
application :: when we know that the array will be sorted by swapping thenn go for selection sort
no.of swaps :::: O(n) in worst case
mean while in bubble sorting: 
no. of swaps :: O(n^2)

*/