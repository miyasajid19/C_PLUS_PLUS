#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "Enter the row and column of matrix A" << endl;
    int row1, column1;
    cin >> row1 >> column1;
    int A[row1][column1];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            cout << "A[" << i << "]" << "[" << j << "]" << endl;
            cin >> A[i][j];
        }
        cout << endl;
    }
    cout << "enter the element that you want to search " << endl;
    int target;
    cin >> target;
    // starting from left buttom corner
    int r = row1-1;
    int c = 0;
    bool found = false;
    while (r >= 0 and c < column1)
    {
        if (A[r][c] == target)
        {
            found = true;
            break;
        }
        else if ((A[r][c] < target))
        {
            c++;
        }
        else
        {
            r--;
        }
        cout<<"searching  at (" <<r+1<<","<<c+1<<")"<< endl;
    }
    if (found)
    {
        cout<<endl<<target << " Found at (" <<r+1<<","<<c+1<<")"<< endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return EXIT_SUCCESS;
}