#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
int main()
{
#ifndef JUDGE_ONLINE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int size;
    cout << "enter the size of array";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i + 1 << "]" << endl;
        cin >> arr[i];
    }
    int maxsum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    cout << maxsum;
    return EXIT_SUCCESS;
}