//
// Created by Arťom Ňorba on 13.01.2022.
//

#include <iostream>
#include "MatrixHelper.h"

void MatrixHelper::doGemSolve() {

    for(int i=0;i<matrix.getRows();i++){
        for(int j=i+1;j<matrix.getRows();j++){
            if(abs(matrix(i,i)) < abs(matrix(j,i))){
                for(int k=0;k<matrix.getColumns();k++){
                    long double first = matrix(i,k);
                    long double second = matrix(j,k);
                    matrix.changeValue(i,k,second);
                    matrix.changeValue(j,k,first);
                }
            }
        }
    }

    for(int i=0;i<matrix.getRows()-1;i++){
        for(int j=i+1;j<matrix.getRows();j++){
            long double f = matrix(j,i) / matrix(i,i);
            for(int k=0;k<matrix.getRows()+1;k++){
                matrix.changeValue(j, k,matrix(j,k)-f*matrix(i,k));
            }
        }
    }

    cout << "\nHere is equations after GEM";
    matrix.printMatrix();
}

void MatrixHelper::calculateResults() {
    matrix.setResultArray();
    for(int i=matrix.getRows()-1;i>=0;i--){
        matrix.addResult(i, matrix(i,matrix.getRows()));
        for(int j=i+1;j<matrix.getRows();j++){
            if(i!=j){
                matrix.addResult(i, matrix.getResultsArray()[i] - matrix(i,j)*matrix.getResultsArray()[j]);
            }
        }
        matrix.addResult(i, matrix.getResultsArray()[i] / matrix(i,i));
    }
}

int MatrixHelper::calculateLeftSideRank() {
    int result = matrix.getRows();
    for (int i = matrix.getRows() - 1; i >= 0; --i) {
        for (int j = 0; j < matrix.getRows(); ++j) {
            if (matrix(i,j) == 0){
                continue;
            }else {
                return result;
            }
        }
        result--;
    }
    return result;
}

int MatrixHelper::calculateRightSideRank() {
    int result = matrix.getRows();
    int j = matrix.getRows();
    for (int i = matrix.getRows() - 1; i >= 0; --i) {
        if (matrix(i,j) == 0){
            result--;
            continue;
        }else {
            return result;
        }
    }
    return result;
}


void MatrixHelper::printResults() {
    int left = calculateLeftSideRank();
    int right = calculateRightSideRank();
    if (left == right){
        if (left == matrix.getRows()){
            cout<<"\nHere are your results\n";
            cout<<"_____________________\n";
            matrix.printResults();
            cout<<"_____________________\n";
        }
        else {
            cout << "\nYour matrix has infinity results\n";
        }
    }
    else{
        if (left < right){
            cout<<"\nI am really sorry but your inputs do not have any solution\n";
        }
        else {
            cout << "How did you do that?";
        }
    }
}
