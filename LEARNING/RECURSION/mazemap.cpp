#include <iostream>
#include <cstdlib>
using namespace std;
int mazeMap(int row, int column, int rows, int columns)
{
    if (row == rows - 1 and column == columns - 1)
        return 1;
    if (row >= rows or column >columns)
        return 0;
    return mazeMap(row + 1, column, rows, columns) + mazeMap(row, column + 1, rows, columns);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
int rows,columns, row,column;
cout<<"enter the dimension  of the maze :: "<<endl;;
cin>>rows>>columns;
cout<<"enter the position :: "<<endl;;
cin>>row>>column;
cout<<"there are "<<mazeMap(row,column,rows,columns)<<" possible in the maze";
    return EXIT_SUCCESS;
}