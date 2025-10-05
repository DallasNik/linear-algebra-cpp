#pragma once
#include <iostream>
#include <vector>

class Matrix
{
private:
    std::size_t rows;
    std::size_t cols;
    std::vector<int> data;

public:
    // Constructors
    Matrix(std::size_t r, std::size_t c) : rows(r), cols(c), data(r * c) {}
    Matrix(std::size_t r, std::size_t c, std::vector<int> vec ) : rows(r), cols(c), data(vec) {}

    std::size_t numRows() const { return rows; }
    std::size_t numCols() const { return cols; }
    std::size_t size() const { return data.size(); }
    bool isSquare() const { return rows == cols; }

    int& operator()(std::size_t r, std::size_t c)
    {
        return data[r * cols + c];
    }
    
    const int& operator()(std::size_t r, std::size_t c) const
    {
        return data[r * cols + c];
    }
 
    void print() const;
    void fill_with_indices();

    friend Matrix operator+(const Matrix& a, const Matrix& b);

    friend Matrix operator-(const Matrix& a, const Matrix& b);

    friend Matrix operator*(const int& kapa, Matrix& a);
    friend Matrix operator*(const Matrix& a,const Matrix& b);

    friend Matrix transpose(const Matrix& a);
};
