#include "matrix.h"

Matrix::Matrix()
{
    matrix = new int *[DEFAULT];
    rows = DEFAULT;
    cols = DEFAULT;

    for (int i = 0; i < DEFAULT; i++)
    {
        matrix[i] = new int[DEFAULT];
    }
    for (int row = 0; row < DEFAULT; row++)
    {
        for (int col = 0; col < DEFAULT; col++)
        {
            matrix[row][col] = 0; // get format "rowcol" e.g. diagonals should be 11, 22, 33...
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete matrix[i];
    }
    delete matrix;
}

int Matrix::at(const int i, const int j) const
{
    // check for error and return -1 if trying to access faulty array element
    if (i > rows or j > cols)
    {
        std::cout << "ERROR IN FUNCTION CALL: MATRIX::AT(" << i << ", " << j
                  << ") ACCESSING VALUE OUT OF RANGE, RETURN STATUS -1" << std::endl;
        return -1;
    }
    return matrix[i][j];
}

std::ostream &operator<<(std::ostream &out, const Matrix &aMatrix)
{

    for (int row = 0; row < aMatrix.numRows(); row++)
    {
        for (int col = 0; col < aMatrix.numCols(); col++)
            out << ':' << aMatrix.at(row, col) << ':';
        out << std::endl;
    }
    return out;
}