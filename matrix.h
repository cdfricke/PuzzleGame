#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
public:
    /*
    Initializes a default square matrix of dimension DEFAULT, filled with matrix element indices.
    */
    Matrix();

    /*
    Destructor, which deletes each of the dynamically stored "rows" and then deletes the
    pointer to the array of rows.
    */
    ~Matrix();

    int numRows() const { return rows; }
    int numCols() const { return cols; }

    /*
    Accessor function for matrix element ij, with error checking
    */
    int at(const int i, const int j) const;

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