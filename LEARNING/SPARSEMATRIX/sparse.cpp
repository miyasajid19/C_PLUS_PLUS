#include <iostream>
#include <cstdlib>
using namespace std;
class Sparse
{
    int **arr;
    int **sparseMatrix;
    int **transposedSparseMatrix;
    int rows;
    int columns;
    int nonZeros;
    int countNonZeros()
    {
        int count = 0;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                    count++;
            }
        }
        return count;
    }

public:
    Sparse(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        arr = new int *[rows];
        for (int i = 0; i < this->rows; i++)
        {
            arr[i] = new int[columns];
        }
        cout << "template created" << endl;
    }
    void setMatrix()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                cout << "Arr[" << i << "][" << j << "] ::: ";
                cin >> arr[i][j];
            }
        }
    }
    void sparseit()
    {
        this->nonZeros = countNonZeros();
        sparseMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
        {
            sparseMatrix[i] = new int[3];
        }
        sparseMatrix[0][0] = this->rows;
        sparseMatrix[0][1] = this->columns;
        sparseMatrix[0][2] = this->nonZeros;
        int k = 1;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    sparseMatrix[k][0] = i;
                    sparseMatrix[k][1] = j;
                    sparseMatrix[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        cout << "sparse matrix created" << endl;
    }
    void displaySparse()
    {
        if (sparseMatrix == nullptr)
        {
            cout << "transpose matrix not created ";
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (int i = 0; i <= this->nonZeros; i++)
        {
            cout << sparseMatrix[i][0] << "\t" << sparseMatrix[i][1] << "\t" << sparseMatrix[i][2] << endl;
        }
    }
    void RowMajorSort()
    {
        for (int i = 1; i <= this->nonZeros; i++)
        {
            for (int j = i + 1; j <= nonZeros; j++)
            {
                if (transposedSparseMatrix[i][0] > transposedSparseMatrix[j][0] || (transposedSparseMatrix[i][0] == transposedSparseMatrix[j][0] && transposedSparseMatrix[i][1] > transposedSparseMatrix[j][1]))
                {
                    swap(transposedSparseMatrix[i], transposedSparseMatrix[j]);
                }
            }
        }
    }
    void Transpose()
    {
        this->nonZeros = countNonZeros();
        transposedSparseMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
        {
            transposedSparseMatrix[i] = new int[3];
        }
        transposedSparseMatrix[0][0] = this->rows;
        transposedSparseMatrix[0][1] = this->columns;
        transposedSparseMatrix[0][2] = this->nonZeros;
        int k = 1;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                if (arr[i][j] != 0)
                {
                    transposedSparseMatrix[k][0] = j;
                    transposedSparseMatrix[k][1] = i;
                    transposedSparseMatrix[k][2] = arr[i][j];
                    k++;
                }
            }
        }
        RowMajorSort();
        cout << " transpose of sparse matrix created" << endl;
    }
    void displayTransposedSparse()
    {
        if (transposedSparseMatrix == nullptr)
        {
            cout << "transpose matrix not created ";
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (int i = 0; i <= this->nonZeros; i++)
        {
            cout << sparseMatrix[i][0] << "\t" << sparseMatrix[i][1] << "\t" << sparseMatrix[i][2] << endl;
        }
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    Sparse mat(3, 3);
    mat.setMatrix();
    mat.sparseit();
    mat.displaySparse();
    mat.Transpose();
    mat.displayTransposedSparse();
    return EXIT_SUCCESS;
}