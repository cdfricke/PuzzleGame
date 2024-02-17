#include "include/matrix.h"

Matrix::Matrix()
{
    matrix = new int *[DEFAULT];
    rows = DEFAULT;
    cols = DEFAULT;
    // dynamically allocate DEFAULT number of rows
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[DEFAULT];
    }

    // load identity matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            matrix[i][j] = 1;
            else
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const int numRows, const int numCols)
{
    // dynamically allocate parameter number of rows
    rows = numRows;
    cols = numCols;
    
    matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        // each matrix[i] is a row.
        matrix[i] = new int[cols];
    }

    // load identity matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
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

void Matrix::setDimensions(const int rows, const int cols)
{
    // TODO: Implement
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