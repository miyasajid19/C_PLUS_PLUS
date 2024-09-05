#include <iostream>
#include<cstdlib>
using namespace std;

void swapAlternate(int *arr, int index, int size)
{
    if(index + 1 >= size)  // Fixing the bounds check
    {
        return;
    }
    swap(arr[index], arr[index+1]); // Swap the current element with the next one
    swapAlternate(arr, index + 2, size); // Recursively swap the next pair
}

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int arr[] = {1, 2, 3, 5, 6}; // Array of size 5
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the correct size of the array
    
    display(arr, size); // Display original array
    swapAlternate(arr, 0, size); // Swap alternate elements
    display(arr, size); // Display array after swapping

    return EXIT_SUCCESS;
}
