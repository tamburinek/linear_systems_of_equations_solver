//
// Created by Arťom Ňorba on 13.01.2022.
//

#ifndef SEMESTRALKA_PJC_MATRIX_H
#define SEMESTRALKA_PJC_MATRIX_H

#include <vector>

using namespace std;

class Matrix {

private:

    int rows;
    int columns;
    vector<vector<double> > values;
    vector<double> results;

public:

    Matrix(int variables) : rows(variables), columns(variables + 1) {}

    int getRows() const;
    int getColumns() const;
    vector<vector<double> > getValues();
    void setValuesBegin(vector<vector<double> > put);
    void changeValue(int row, int column, double value);
    void printMatrix();
    vector<double> getResultsArray();
    void setResults(vector<double> res);
    void addResult(int pos, double res);
    void printResults();
    void setResultArray();

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;

};


#endif //SEMESTRALKA_PJC_MATRIX_H
