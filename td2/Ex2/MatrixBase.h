#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data;  // vecteur template en 2D
    size_t rows;
    size_t cols;
public:
    MatrixBase();
    MatrixBase(size_t rows, size_t cols, const T& init = T());
    MatrixBase(const std::vector<std::vector<T>>& values);
    virtual ~MatrixBase() = default;
    void addElement(size_t i, size_t j, const T& value);
    T getElement(size_t i, size_t j) const;
    size_t getRows() const;
    size_t getCols() const;
    virtual void Display(std::ostream& os = std::cout) const;
};

template <typename T>
class MatrixNumerical;
template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m, size_t p, size_t q);
template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:

    MatrixNumerical();
    MatrixNumerical(size_t rows, size_t cols, const T& init = T());
    MatrixNumerical(const std::vector<std::vector<T>>& values);
    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator/(const MatrixNumerical<T>& other) const;  
    static MatrixNumerical<T> getIdentity(int n);
};

#include "MatrixBase.cpp"

#endif