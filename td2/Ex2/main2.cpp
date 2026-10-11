#include <iostream>
#include "MatrixBase.h"

int main() {
    
    MatrixBase<int> base(2, 3, 0);
    base.addElement(0, 1, 5);
    base.addElement(1, 2, 7);
    std::cout << "MatrixBase (" << base.getRows() << "x" << base.getCols() << ") :\n";
    base.Display();
    std::cout << "Element (1,2) = " << base.getElement(1, 2) << "\n\n";
    MatrixNumerical<double> A({{2, 1, 1},{1, 3, 2},{1, 0, 0}});
    MatrixNumerical<double> B({{1, 2, 0},{0, 1, 3},{4, 0, 1}});
    std::cout << "A :\n";  A.Display();
    std::cout << "B :\n";  B.Display();
    std::cout << "\nA + B :\n"; (A + B).Display();
    std::cout << "\nA - B :\n"; (A - B).Display();
    std::cout << "\nA * B :\n"; (A * B).Display();
    std::cout << "\ndet(A) = " << A.getDeterminant() << "\n";
    std::cout << "\nInverse de A :\n";
    MatrixNumerical<double> invA = A.getInverse();
    invA.Display();
    std::cout << "\nA * A^-1 (doit donner l'identite) :\n";
    (A * invA).Display();
    std::cout << "\nA / B :\n";
    (A / B).Display();
    std::cout << "\nIdentite 4x4 :\n";
    MatrixNumerical<double>::getIdentity(4).Display();
    return 0;
}