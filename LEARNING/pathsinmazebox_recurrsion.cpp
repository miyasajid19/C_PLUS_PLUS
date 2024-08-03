#include<iostream>
#include<cstdlib>
using namespace std;

int countpathmazebox(int size, int i, int j)
{
    if (i == size - 1 && j == size - 1)
    {
        return 1;
    }
    if (i >= size || j >= size)
    {
        return 0;
    }
    return countpathmazebox(size, i + 1, j) + countpathmazebox(size, i, j + 1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    cout << "Enter the dimension of the maze box: "<<endl;
    int size;
    cin >> size;

    cout << "Enter starting x coordinate: "<<endl;
    int x;
    cin >> x;

    cout << "Enter starting y coordinate: "<<endl;
    int y;
    cin >> y;

    cout << "Number of paths: " << countpathmazebox(size, x, y) << endl;

    return EXIT_SUCCESS;
}
