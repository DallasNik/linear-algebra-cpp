#include <vector>
#include <iostream>

template <typename T>
class Matrix
{
private:
    std::size_t rows;
    std::size_t cols;
    std::vector<T> data;

public:
    // Constructor
    Matrix(std::size_t r, std::size_t c) : rows(r), cols(c), data(r * c) {}

    T& operator()(std::size_t r, std::size_t c)
    {
        return data[r * cols + c];
    }
    
    const T& operator()(std::size_t r, std::size_t c) const
    {
        return data[r * cols + c];
    }

    std::size_t numRows() const { return rows; }
    std::size_t numCols() const { return cols; }
    std::size_t size() const { return data.size(); }

    void print() const
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

    void fill_with_indices() {
        for (std::size_t i = 0; i < rows; ++i)
        {
            for (std::size_t j = 0; j < cols; ++j)
            {
                (*this)(i, j) = static_cast<T>(i * rows + j);
            }
        }
    }`


    friend Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.numRows() != b.numRows() || a.numCols() != b.numCols())
        {
            throw std::invalid_argument("Matrices must have the same dimensions for addition.");
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
    }

};