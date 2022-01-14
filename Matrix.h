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
    vector<vector<long double> > values;
    vector<long double> results;

public:

    Matrix(int variables) : rows(variables), columns(variables + 1) {}

    int getRows() const;
    int getColumns() const;
    vector<vector<long double> > getValues();
    void setValuesBegin(vector<vector<long double> > put);
    void changeValue(int row, int column, long double value);
    void printMatrix();
    vector<long double> getResultsArray();
    void setResults(vector<long double> res);
    void addResult(int pos, long double res);
    void printResults();
    void setResultArray();

    long double& operator()(int row, int col);
    const long double& operator()(int row, int col) const;

};


#endif //SEMESTRALKA_PJC_MATRIX_H
