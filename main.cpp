#include <iostream>
#include "Matrix.cpp"


int main()
{

    Matrix<int> mat(3, 3);
    
    std::cout << "Matrix size: " << mat.size() << std::endl;
    std::cout << "Number of rows: " << mat.numRows() << std::endl;
    std::cout << "Number of columns: " << mat.numCols() << std::endl;

    mat.print();

    mat.fill_with_indices();

    mat.print();
    
    return 0;
}