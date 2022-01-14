//
// Created by Arťom Ňorba on 13.01.2022.
//

#include <iostream>
#include <iomanip>
#include "Matrix.h"

int Matrix::getRows() const{
    return this->rows;
}

int Matrix::getColumns() const {
    return this->columns;
}

void Matrix::setValuesBegin(vector<vector<long double> > put) {
    this->values = put;
}

long double& Matrix::operator()(const int row, const int col) {
    return this->values[row][col];
}
const long double &Matrix::operator()(const int row, const int col) const {
    return this->values[row][col];
}

void Matrix::changeValue(int row, int column, long double value) {
    if (((row + 1) > this->rows) || ((column + 1 ) > this->columns)){
        cout << "u can not change that position because this position does not exist" << endl;
        return;
    }
    this->values[row][column] = value;
}

void Matrix::printMatrix() {
    cout << setprecision(3) << fixed;
    cout << endl << "Your equations look like this" << endl;
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            if (j == columns - 2){
                cout << this->values[i][j] << " x" <<j << " = ";
            }
            else if (j == columns - 1){
                cout << this->values[i][j];
            }
            else {
                cout << this->values[i][j] << " x" <<j << " + ";
            }
        }
        cout << endl;
    }

}

vector<long double> Matrix::getResultsArray() {
    return this->results;
}

void Matrix::addResult(int pos, long double res) {
    this->results[pos] = res;
}

void Matrix::printResults() {
    for(int i=0; i < results.size();i++){
        if (i == results.size()-1){
            cout<<  " x" << i+1 << " = " << results[i]<<" ";
        }
        else if (i == 0){
            cout<<  "| x" << i+1 << " = " << results[i]<<" |";
        }
        else {
            cout<<  " x" << i+1 << " = " << results[i]<<" |";
        }


    }
    cout << endl;
}

void Matrix::setResultArray() {
    vector<long double> resultik;
    for (int i = 0; i < rows; ++i) {
        resultik.push_back(0);
    }
    this->results = resultik;
}
