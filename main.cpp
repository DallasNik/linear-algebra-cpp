#include <iostream>
#include "Matrix.h"


int main()
{

    Matrix mat(3, 3);
    
    std::cout << "Matrix size: " << mat.size() << std::endl;
    std::cout << "Number of rows: " << mat.numRows() << std::endl;
    std::cout << "Number of columns: " << mat.numCols() << std::endl;

    mat.print();
    mat.fill_with_indices();
    mat.print();
    
    Matrix a(3, 3);
    Matrix b(3, 3);
    a.fill_with_indices();
    b.fill_with_indices();
    Matrix c = a - b;
    c.print();
    c = a + b;
    c.print();

    c = 6 * a;
    c.print();

    Matrix d(2, 3, {1, 2, 3, 4, 5, 6});
    d.print();

    transpose(d).print();
    

    return 0;
}