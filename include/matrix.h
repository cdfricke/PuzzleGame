/*
Programmer: Connor Fricke (cd.fricke23@gmail.com)
Latest Revision:
    10-Feb-2024  Original version
    16-Feb-2024  Implemented setElement function

Matrix class to store integers in a dynamic 2D array.
Elements indices are zero-indexed (a 3x3 matrix, for example)
    00 01 02
    10 11 12
    20 21 22
Thus, the "first" row and "first" column element can be accessed by
    matrix.at(0, 0);
    matrix.setElement(0, 0, n);
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
public:
    /*
    Matrix::Matrix()
    Initializes a default square IDENTITY matrix of dimension DEFAULT.
    */
    Matrix();

    /*
    Matrix::Matrix(const int, const int)
    Initializes a matrix with rows equal to the first paramater, and columns equal to the second parameter.
    */
    Matrix(const int rows, const int cols);

    /*
    Matrix::~Matrix()
    Destructor, which deletes each of the dynamically stored "rows" and then deletes the
    pointer to the array of rows.
    */
    ~Matrix();

    /*
    int Matrix::numRows() const
    Returns the number of rows stored by the matrix (the private data member)
    */
    int numRows() const { return rows; }

    /*
    int Matrix::numCols() const
    Returns the number of columns stored by the matrix (the private data member)
    */
    int numCols() const { return cols; }

    /*
    int Matrix::at(const int, const int) const
    Accessor function for matrix element ij, with error checking.
    Returns the value stored in the ith row (first parameter), jth column (second parameter).
    Note that matrix elements are zero-indexed, so matrix.at(0,0) gives the value in the 
    first row, first column.
    */
    int at(const int i, const int j) const;

    /*
    int Matrix::setElement(const int i, const int j, const int set)
    Mutator function for matrix element ij, with error checking.
    Assigns the third passed parameter (set) to the element of the matrix ij, which is the ith row,
    and jth column (zero-indexed).
    Returns an integer -1 if element accessed out of range, otherwise returns 0.
    */
    int setElement(const int i, const int j, const int set);

    /*
    void Matrix::setDimensions(const int rows, const int cols)
    setDimensions can be used to grow or shrink a matrix. 
    If the matrix is to be shrunk, terms outside the new "bounds" will be deleted, and unrecoverable.
    If the matrix is to be grown, new elements are initialized to zero. TODO: IMPLEMENT
    */
    void setDimensions(const int numRows, const int numCols);

    /*
    Overloaded << operator for easy output of Matrix objects.
    */
    friend std::ostream &operator<<(std::ostream &out, const Matrix &aMatrix);

private:
    int DEFAULT = 3;
    int rows, cols;
    int **matrix;
};

#endif