#include <iostream>
#include <cstdlib>
using namespace std;
class sparseMatrix
{
    int **array=nullptr;
    int rows,columns,nonZeros;
    public:
    sparseMatrix():rows(0),columns(0),nonZeros(0){}
    sparseMatrix(int rows, int columns,int nonZeros)
    {
        this->rows=rows+1;
        this->columns=columns+1;
        array=new int*[rows];
        for (int i =0;i<rows;++i)
        {
            array[i]= new int[3]();
        }
        array[0][0]=rows;
        array[0][1]=columns;
        array[0][2]=nonZeros;
        cout<<"Template created"<<endl;
    }
    void setSparse(int row, int column,int value)
    {
        if(row>rows and column>columns)
        {
            cout<<"index out of bound"<<endl;
            return;
        }
        array[row+1][column+1]=value;
    }
    void display()
    {
        for ( int i =0;i<nonZeros;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(array[i][j]!=0)
                {
                    cout<<array[i][j]<<" ";
                }
                else
                {
                    cout<<0<<" ";
                }
            }
            cout<<endl;

        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("..input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
cout<<"all i want was the love and what i get is the pain";
sparseMatrix matrix(3,3,3);
matrix.setSparse(0,0,1);
matrix.setSparse(1,2,2);
matrix.setSparse(2,1,3);
matrix.display();
    return EXIT_SUCCESS;
}