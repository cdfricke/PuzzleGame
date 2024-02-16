#include "include/matrix.h"

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
            matrix[row][col] = row + col;
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
    if (i >= rows or j >= cols)
    {
        std::cerr << "ERROR IN FUNCTION CALL: Matrix::at(" << i << ", " << j
                  << ") ACCESSING VALUE OUT OF RANGE, RETURN STATUS -1." << std::endl;
        return -1;
    }
    return matrix[i][j];
}

int Matrix::setElement(const int i, const int j, const int set)
{
    if (i >= rows or j >= cols)
    {
        std::cerr << "ERROR IN FUNCTION CALL: Matrix::setElement(" << i << ", " << j << ", " << set
                  << ") ACCESSING VALUE OUT OF RANGE. RETURN STATUS -1." << std::endl;
        return -1;
    }
    matrix[i][j] = set;
    return 0;
}

std::ostream &operator<<(std::ostream &out, const Matrix &aMatrix)
{

    for (int row = 0; row < aMatrix.numRows(); row++)
    {
        for (int col = 0; col < aMatrix.numCols(); col++)
        {
            if (aMatrix.at(row, col) < 0)
                out << ":" << aMatrix.at(row, col) << " :";
            else
                out << ": " << aMatrix.at(row, col) << " :";
        }
        out << std::endl;
    }
    return out;
}