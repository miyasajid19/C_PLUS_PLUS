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
    int row, column;
    cout << "enter the row and column of the matrix" << endl;
    cin >> row >> column;
    int arr[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "arr[" << i + 1 << "]" << "[" << j + 1 << "]" << endl;
            cin >> arr[i][j];
        }
    }
    int key;
    bool flag = false;
    cout << "enter the element to search" << endl;
    cin >> key;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] == key)
            {
                flag = true;
            }
            if (flag)
            {
                cout << "found in the row = "<< i + 1 << "and column = " << j+1 <<endl;
            }
            else
            {
                cout << "not found";
            }
        }
    }

    return EXIT_SUCCESS;
}