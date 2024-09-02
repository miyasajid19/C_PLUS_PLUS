#include <iostream>
#include <cstdlib>
using namespace std;

class Sparse
{
public:
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

    Sparse(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        arr = new int *[rows];
        for (int i = 0; i < this->rows; i++)
        {
            arr[i] = new int[columns];
        }
        cout << "Template created" << endl;
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
        cout << "Sparse matrix created" << endl;
    }

    void displaySparse()
    {
        if (sparseMatrix == nullptr)
        {
            cout << "Sparse matrix not created" << endl;
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
                if (transposedSparseMatrix[i][0] > transposedSparseMatrix[j][0] ||
                    (transposedSparseMatrix[i][0] == transposedSparseMatrix[j][0] && transposedSparseMatrix[i][1] > transposedSparseMatrix[j][1]))
                {
                    swap(transposedSparseMatrix[i], transposedSparseMatrix[j]);
                }
            }
        }
    }

    void Transpose()
    {
        transposedSparseMatrix = new int *[this->nonZeros + 1];
        for (int i = 0; i <= this->nonZeros; i++)
        {
            transposedSparseMatrix[i] = new int[3];
        }
        transposedSparseMatrix[0][0] = this->columns; // rows and columns swapped for transpose
        transposedSparseMatrix[0][1] = this->rows;
        transposedSparseMatrix[0][2] = this->nonZeros;

        int k = 1;
        for (int i = 1; i <= this->nonZeros; i++)
        {
            transposedSparseMatrix[k][0] = sparseMatrix[i][1];
            transposedSparseMatrix[k][1] = sparseMatrix[i][0];
            transposedSparseMatrix[k][2] = sparseMatrix[i][2];
            k++;
        }
        RowMajorSort();
        cout << "Transpose of sparse matrix created" << endl;
    }

    void displayTransposedSparse()
    {
        if (transposedSparseMatrix == nullptr)
        {
            cout << "Transpose matrix not created" << endl;
            return;
        }
        cout << "rows\tcolumns\tvalues\n";
        for (int i = 0; i <= this->nonZeros; i++)
        {
            cout << transposedSparseMatrix[i][0] << "\t" << transposedSparseMatrix[i][1] << "\t" << transposedSparseMatrix[i][2] << endl;
        }
    }
    void addition(Sparse other)
    {
        int result[this->rows][3];
        result[0][0] = this->rows;
        result[0][1] = this->columns;
        result[0][2] = 0;
        int k = 1;
        if (this->rows == other.rows and this->columns == other.columns)
        {
            int size1 = this->nonZeros, size2 = other.nonZeros;
            int index1 = 1;
            int index2 = 1;
            int index3 = 1;
            while (index1 != this->nonZeros and index2 != other.nonZeros)
            {
                if ((sparseMatrix[index1][0] == other.sparseMatrix[index2][0]))
                {
                    if (sparseMatrix[index1][1] == other.sparseMatrix[index2][1])
                    {
                        result[index3][0] = sparseMatrix[index1][0];
                        result[index3][1] = sparseMatrix[index1][1];
                        result[index3][2] = sparseMatrix[index1][2] + other.sparseMatrix[index1][2];
                        index1++;
                        index2++;
                        index3++;
                    }
                    else if (sparseMatrix[index1][1] < other.sparseMatrix[index1][1])
                    {
                        result[index3][0] = sparseMatrix[index1][0];
                        result[index3][1] = sparseMatrix[index1][1];
                        result[index3][2] = sparseMatrix[index1][2];
                        index1++;
                        index3++;
                    }
                    else
                    {
                        result[index3][0] = other.sparseMatrix[index1][0];
                        result[index3][1] = other.sparseMatrix[index1][1];
                        result[index3][2] = other.sparseMatrix[index1][2];
                        index2++;
                        index3++;
                    }
                }
            }
            while (index1 != this->nonZeros)
            {
                result[index3][0] = sparseMatrix[index1][0];
                result[index3][1] = sparseMatrix[index1][1];
                result[index3][2] = sparseMatrix[index1][2];
                index1++;
                index3++;
            }
            while (index2 != other.nonZeros)
            {
                result[index3][0] = other.sparseMatrix[index1][0];
                result[index3][1] = other.sparseMatrix[index1][1];
                result[index3][2] = other.sparseMatrix[index1][2];
                index1++;
                index3++;
            }
            result[0][2] = index3 - 1;
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
