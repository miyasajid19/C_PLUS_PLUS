/*
the size of array is N
and there occurs 0 to N-1 elements unique elements and one duplciate
find that duplicates
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int Duplicate(int *arr, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
    int arr[] = {1,2,3,4,5,6,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Unique :: " << Duplicate(arr, size);
    return EXIT_SUCCESS;
}