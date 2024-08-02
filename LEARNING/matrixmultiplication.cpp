#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cout<<"Enter the row and column of matrix A"<<endl;
    int row1,column1;
    cin>>row1>>column1;
    int A[row1][column1];
    for(int i =0;i<row1;i++)
    {
        for (int j=0;j<column1;j++)
        {
            cout<<"A["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>A[i][j];
        }
        cout<<endl;
    }
        cout<<"Enter the row and column of matrix B"<<endl;
    int row2,column2;
    cin>>row2>>column2;
    int B[row2][column2];
    for(int i =0;i<row2;i++)
    {
        for (int j=0;j<column2;j++)
        {
            cout<<"B["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>B[i][j];
        }
        cout<<endl;
    }
    //mulitplication
    if (row2==column1)
    {
        int result[row1][column2];
        for (int i=0;i<row1;i++)
        {
            for (int j=0;j<column2;j++)
            {
                result[i][j]=0;
                for(int k=0;k<row2;k++)
                {
                    
                result[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    for (int i=0;i<row1;i++)
    {
        for(int j=0;j<column2;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    else{
        cout<<"matrix multiplication is not possible";
    }
    return EXIT_SUCCESS;
}