#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    #ifndef JUDGE_ONLINE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int row,column;
    cout<<"enter the row and column of the matrix"<<endl;
    cin>>row>>column;
    int arr[row][column];
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
            cout<<"arr["<<i+1<<"]"<<"["<<j+1<<"]"<<endl;
            cin>>arr[i][j];
        }
    }
    int rowstart=0,rowend=row-1, columnstart=0,columnend=column-1;
    while((rowstart<=rowend)&&(columnstart<=columnend))
    {
        for (int j=columnstart;j<=columnend;j++)
        {
            cout<<arr[rowstart][j]<<" ";
        }
        rowstart++;
        for (int i=rowstart;i<=rowend;i++)
        {
            cout<<arr[i][columnend]<<" ";
        }
        columnend--;
        for(int j=columnend;j>=columnstart;j--)
        {
            cout<<arr[rowend][j]<<" ";
        }
        rowend--;
        for(int i=rowend;i>=rowstart;i--)
        {
            cout<<arr[i][columnstart]<<" ";
        }
        columnstart++;

    }
 
    return EXIT_SUCCESS;
}