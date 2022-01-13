//
// Created by Arťom Ňorba on 13.01.2022.
//

#ifndef SEMESTRALKA_PJC_MATRIXHELPER_H
#define SEMESTRALKA_PJC_MATRIXHELPER_H


#include "Matrix.h"

class MatrixHelper {

private:
    Matrix matrix;


public:

    explicit MatrixHelper(const Matrix &matrix) : matrix(matrix) {}

    void solveMatrix();

    void printResults();
};


#endif //SEMESTRALKA_PJC_MATRIXHELPER_H