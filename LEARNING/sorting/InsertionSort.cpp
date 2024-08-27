#include <iostream>
#include <cstdlib>
using namespace std;
void insertionSort(int *arr,int size)
{
    cout<<size<<endl;
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}
int main()
{
    int arr[] = {4,2, 2, 1, 2};
    int size=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,size);
    for (auto a : arr)
    {
        cout << a << " ";
    }
    return EXIT_SUCCESS;
}
/*
intutions:
    repeatedly take elements from unsorted sub array and then insert it into the sorted sub array
stabilty:
    it is stable sorting algorithm 
worst time complexity:
    O(n^2)
best time complexity:
    O(n)
application:
    when there is few unsorted elements
*/