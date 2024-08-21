#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix {
    int rows, columns, nonZeros;
    int **arr;
    int **sparse;

public:
    // Constructor
    Matrix(int rows, int columns) : rows(rows), columns(columns), nonZeros(0) {
        arr = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            arr[i] = new int[columns](); // Initialize elements to zero
        }
        sparse = nullptr; // Initialize sparse matrix pointer
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        if (sparse) {
            for (int i = 0; i < nonZeros + 1; ++i) {
                delete[] sparse[i];
            }
            delete[] sparse;
        }
    }

    // Method to set matrix values
    void setMatrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << "arr[" << i << "][" << j << "]::" << endl;
                cin >> arr[i][j];
            }
        }
    }

    // Method to get matrix values
    void getMatrix() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Count non-zero elements
    int countNonZeros() {
        nonZeros = 0; // Reset nonZeros count
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (arr[i][j] != 0) {
                    ++nonZeros;
                }
            }
        }
        return nonZeros;
    }

    // Display sparse matrix
    void getSparsed() const {
        if (sparse) {
            cout << "Rows    Columns    Value" << endl;
            for (int i = 0; i < nonZeros + 1; ++i) {
                cout << sparse[i][0] << "    " << sparse[i][1] << "       " << sparse[i][2] << endl;
            }
        } else {
            cout << "Sparse matrix not created yet." << endl;
        }
    }

    // Convert to sparse matrix
    void SparseIt() {
        countNonZeros(); // Ensure nonZeros is updated
        sparse = new int*[nonZeros + 1];
        for (int i = 0; i < nonZeros + 1; ++i) {
            sparse[i] = new int[3];
        }
        sparse[0][0] = rows;
        sparse[0][1] = columns;
        sparse[0][2] = nonZeros;

        int temp = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (arr[i][j] != 0) {
                    sparse[temp][0] = i;
                    sparse[temp][1] = j;
                    sparse[temp][2] = arr[i][j];
                    ++temp;
                }
            }
        }
        cout << "Sparse matrix created." << endl;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cout << "Enter the rows and columns of the matrix:" << endl;
    int r, c;
    cin >> r >> c;
    Matrix matrix(r, c);
    matrix.setMatrix();
    matrix.getMatrix();
    matrix.SparseIt();
    matrix.getSparsed();
    return EXIT_SUCCESS;
}
