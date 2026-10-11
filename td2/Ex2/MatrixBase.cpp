#ifndef MATRIXBASE_CPP
#define MATRIXBASE_CPP
#include "MatrixBase.h"

template <typename T>
MatrixBase<T>::MatrixBase() : data(), rows(0), cols(0) {}

template <typename T>
MatrixBase<T>::MatrixBase(size_t r, size_t c, const T& init)
    : data(r, std::vector<T>(c, init)), rows(r), cols(c) {}

template <typename T>
MatrixBase<T>::MatrixBase(const std::vector<std::vector<T>>& values)
    : data(values), rows(values.size()),
      cols(values.empty() ? 0 : values[0].size()) {
    for (const auto& row : values)
        if (row.size() != cols)
            throw std::invalid_argument("Toutes les lignes doivent avoir la meme taille");
}

template <typename T>
void MatrixBase<T>::addElement(size_t i, size_t j, const T& value) {
    if (i >= rows || j >= cols) throw std::out_of_range("Indice hors limites");
    data[i][j] = value;
}

template <typename T>
T MatrixBase<T>::getElement(size_t i, size_t j) const {
    if (i >= rows || j >= cols) throw std::out_of_range("Indice hors limites");
    return data[i][j];
}

template <typename T>
size_t MatrixBase<T>::getRows() const { return rows; }

template <typename T>
size_t MatrixBase<T>::getCols() const { return cols; }

template <typename T>
void MatrixBase<T>::Display(std::ostream& os) const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            os << data[i][j] << "\t";
        os << "\n";
    }
}
template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t r, size_t c, const T& init)
    : MatrixBase<T>(r, c, init) {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(const std::vector<std::vector<T>>& values)
    : MatrixBase<T>(values) {}

template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& m, size_t p, size_t q) {
    size_t n = m.getRows();
    MatrixNumerical<T> sub(n - 1, n - 1);
    size_t r = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i == p) continue;
        size_t c = 0;
        for (size_t j = 0; j < n; ++j) {
            if (j == q) continue;
            sub.addElement(r, c, m.getElement(i, j));
            ++c;
        }
        ++r;
    }
    return sub;
}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->rows != this->cols)
        throw std::logic_error("Determinant : la matrice doit etre carree");
    size_t n = this->rows;
    if (n == 0) return T(1);
    if (n == 1) return this->data[0][0];
    if (n == 2)
        return this->data[0][0] * this->data[1][1]
             - this->data[0][1] * this->data[1][0];
    T det = T(0);
    for (size_t j = 0; j < n; ++j) {
        T sign = (j % 2 == 0) ? T(1) : T(-1);
        det += sign * this->data[0][j] * getCoFactor(*this, 0, j).getDeterminant();
    }
    return det;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    T det = getDeterminant();
    if (det == T(0))
        throw std::runtime_error("Matrice non inversible (determinant = 0)");

    size_t n = this->rows;
    MatrixNumerical<T> inv(n, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            T sign = ((i + j) % 2 == 0) ? T(1) : T(-1);
            T cof = sign * getCoFactor(*this, i, j).getDeterminant();
            inv.addElement(j, i, cof / det);  // transposée
        }
    }
    return inv;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& o) const {
    if (this->rows != o.rows || this->cols != o.cols)
        throw std::invalid_argument("Addition : dimensions differentes");
    MatrixNumerical<T> res(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            res.data[i][j] = this->data[i][j] + o.data[i][j];
    return res;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& o) const {
    if (this->rows != o.rows || this->cols != o.cols)
        throw std::invalid_argument("Soustraction : dimensions differentes");
    MatrixNumerical<T> res(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < this->cols; ++j)
            res.data[i][j] = this->data[i][j] - o.data[i][j];
    return res;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T>& o) const {
    if (this->cols != o.rows)
        throw std::invalid_argument("Multiplication : dimensions incompatibles");
    MatrixNumerical<T> res(this->rows, o.cols, T(0));
    for (size_t i = 0; i < this->rows; ++i)
        for (size_t j = 0; j < o.cols; ++j)
            for (size_t k = 0; k < this->cols; ++k)
                res.data[i][j] += this->data[i][k] * o.data[k][j];
    return res;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T>& o) const {
    return (*this) * o.getInverse();
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int n) {
    if (n < 0) throw std::invalid_argument("Taille negative");
    MatrixNumerical<T> id(n, n, T(0));
    for (int i = 0; i < n; ++i) id.data[i][i] = T(1);
    return id;
}

#endif