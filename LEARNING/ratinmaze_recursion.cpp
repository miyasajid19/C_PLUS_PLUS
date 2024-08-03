/*
backtracking is an algrothmic-technique for solving recursive problems by trying to build
every possible solutions incrementally and removing those solutions that fails to
satisfy teh constraints of the problem at any point of time
*/
#include <iostream>
using namespace std;

bool canMove(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **track)
{
    if (x == n - 1 && y == n - 1)
    {
        track[x][y] = 1;
        return true;
    }

    if (canMove(arr, x, y, n))
    {
        track[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, track))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, track))
        {
            return true;
        }
        track[x][y] = 0; // backtracking
    }

    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout << "Enter the dimension of the maze: " << endl;
    int size;
    cin >> size;

    int **arr = new int *[size];
    int **track = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size]();
        track[i] = new int[size]();
    }

    cout << "Enter the maze (0 for blocked, 1 for open): " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (ratInMaze(arr, 0, 0, size, track))
    {
        cout << "The path through the maze is: " << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << track[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No path found" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
        delete[] track[i];
    }
    delete[] arr;
    delete[] track;

    return 0;
}
