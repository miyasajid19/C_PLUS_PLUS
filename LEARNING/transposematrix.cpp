#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"Enter the row and column of matrix"<<endl;
    int row,column;
    cin>>row>>column;
    int arr[row][column];
    for(int i =0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
            cout<<"Arr["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl<<"Transposed matrix is "<<endl;
    int transpose[column][row];
    for(int i =0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
         transpose[j][i]=arr[i][j];
        }
    }
    for (int i=0;i<column;i++)
    {
        for (int j=0;j<row;j++)
        {
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    return EXIT_SUCCESS;
}