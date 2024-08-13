// program to count the total no of pairs that meets the sum
#include <iostream>
#include <cstdlib>
using namespace std;
int check(int arr[], int size, int targetSum)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[i] + arr[j] == targetSum)
            {
                cout << "index " << i << " and  index " << j << endl;
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int *arr = nullptr;
    cout << "enter how many data do you have" << endl;
    int size;
    cin >> size;
    arr = new int[size]();
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << endl;
        cin >> arr[i];
    }
    cout << "Enter the target sum :" << endl;
    int targetsum;
    cin >> targetsum;
    int count=check(arr, size, targetsum);
    cout << "Total possible pairs : " << count;

    return 0;
}