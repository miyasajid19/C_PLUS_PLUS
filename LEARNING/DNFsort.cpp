#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void dnfsort(int arr[],int size)
{
    int low=0;
    int mid=0;
    int high=size-1;
    while(mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr,mid,high);
            mid++;
            high--;
        }
    }
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

    dnfsort(arr, size);

    cout << "\nSorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i] << endl;
    }

    delete[] arr;
    return EXIT_SUCCESS;
}
//DNF----> Dutch National Flag