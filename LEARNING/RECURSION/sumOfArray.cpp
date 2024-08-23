#include <iostream>
#include <cstdlib>
using namespace std;

int SumElement(int *arr, int index, int size)
{
    if (index == size - 1)
    {
        return arr[index];
    }
    return arr[index]+ SumElement(arr, index + 1, size);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int *arr = nullptr;
    int *size = new int;

    cout << "Enter the size of the array: ";
    cin >> *size;

    // Allocate memory for array
    arr = new int[*size];

    for (int i = 0; i < *size; i++)
    {
        cout << "Enter element " << i + 1 << ": "<<endl;
        cin >> arr[i];
    }

    cout << "The sum of all the  element present in the array is " << SumElement(arr, 0, *size) << endl;

    // Deallocate memory
    delete[] arr;
    delete size;

    return EXIT_SUCCESS;
}
