#include <iostream>
#include<cstdlib>
#include "sparse.h"
using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
int rows1,cols1;
    cout << "Enter dimensions for the first sparse matrix (rows columns): ";
    cin >> rows1 >> cols1;
    Sparse mat1(rows1, cols1);
    cout << "Enter values for the first sparse matrix:" << endl;
    mat1.setMatrix();
    mat1.sparseit();
    cout << "Sparse matrix 1:" << endl;
    mat1.displaySparse();
    mat1.Transpose();
    cout << "transpose matrix 1:" << endl;
    mat1.displayTransposedSparse();
    return EXIT_SUCCESS;
}