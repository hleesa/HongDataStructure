#include <cassert>
#include <iostream>
#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(int row, int col) : numRows(row), numCols(col), values(new float[row * col]) {
    for (int i = 0; i < row * col; ++i) {
        values[i] = 0.0f;
    }
}

Matrix::Matrix(const Matrix& other) : numRows(other.numRows), numCols(other.numCols),
                                      values(new float[numRows * numCols]) {
    for (int i = 0; i < numRows * numCols; ++i) {
        values[i] = other.values[i];
    }
}

Matrix::~Matrix() {
    if (values) {
        delete[] values;
    }
}

void Matrix::setValue(int row, int col, float value) {
    values[row * numCols + col] = value;
}

float Matrix::getValue(int row, int col) const {
    return values[row * numCols + col];
}

Matrix Matrix::transpose() {
    Matrix transMat(numCols, numRows);

    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            transMat.setValue(c, r, getValue(r, c));
        }
    }

    return transMat;
}

Matrix Matrix::add(const Matrix& other) {
    assert(other.numRows == numRows);
    assert(other.numCols == numCols);

    Matrix sumMat(numRows, numCols);

    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            sumMat.setValue(r, c, getValue(r, c) + other.getValue(r, c));
        }
    }

    return sumMat;
}

void Matrix::print() {
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            cout << values[r * numCols + c] << " ";
        }
        cout << '\n';
    }
}