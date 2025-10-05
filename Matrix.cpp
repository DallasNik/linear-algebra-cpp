#include "Matrix.h"

void Matrix::print() const
{
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::fill_with_indices() {
    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            (*this)(i, j) = static_cast<int>(i * rows + j);
        }
    }
}

Matrix operator+(const Matrix& a, const Matrix& b)
{
    if (a.numRows() != b.numRows() || a.numCols() != b.numCols())
    {
        // throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        std::cout << "Matrices must have the same dimensions for addition." << std::endl;
        exit(1);
    }

    Matrix result(a.numRows(), a.numCols());
    for (std::size_t i = 0; i < a.numRows(); ++i)
    {
        for (std::size_t j = 0; j < a.numCols(); ++j)
        {
            result(i, j) = a(i, j) + b(i, j);
        }
    }
    return result;
};

Matrix operator-(const Matrix& a, const Matrix& b)
{
    if (a.numRows() != b.numRows() || a.numCols() != b.numCols())
    {
        // throw std::invalid_argument("Matrices must have the same dimensions for addition.");
        std::cout << "Matrices must have the same dimensions for subtraction." << std::endl;
        exit(1);
    }

    Matrix result(a.numRows(), a.numCols());
    for (std::size_t i = 0; i < a.numRows(); ++i)
    {
        for (std::size_t j = 0; j < a.numCols(); ++j)
        {
            result(i, j) = a(i, j) - b(i, j);
        }
    }
    return result;
};


Matrix operator*(const int& kapa, Matrix& a)
{
    for(std::size_t i = 0; i < a.numRows(); ++i)
    {
        for (std::size_t j = 0; j < a.numCols(); ++j)
        {
            a(i, j) = kapa * a(i, j);
        }
    }
    return a;
};

Matrix operator*(const Matrix& a,const Matrix& b)
{
    if (a.numCols() != b.numRows())
    {
        std::cout << "Number of columns of first matrix must be equal to number of rows of second." << std::endl;
        exit(1);
    }

    Matrix result(a.numRows(), b.numCols());
    for (std::size_t i = 0; i < a.numRows(); ++i)
    {
        for (std::size_t j = 0; j < b.numCols(); ++j)
        {
            result(i, j) = 0;
            for (std::size_t k = 0; k < a.numCols(); ++k)
            {
                result(i, j) += a(i, k) * b(k, j);
            }
        }
    }
    return result;
}


Matrix transpose(const Matrix& a)
{
    Matrix result(a.numCols(), a.numRows());
    for (std::size_t i = 0; i < a.numRows(); ++i)
    {
        for (std::size_t j = 0; j < a.numCols(); ++j)
        {
            result(j, i) = a(i, j);
        }
    }
    return result;
}