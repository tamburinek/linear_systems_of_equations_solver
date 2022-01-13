//
// Created by Arťom Ňorba on 13.01.2022.
//

#include <iostream>
#include "MatrixHelper.h"

void MatrixHelper::solveMatrix() {
    for(int i=0;i<matrix.getRows();i++){
        for(int j=i+1;j<matrix.getRows();j++){
            if(abs(matrix(i,i)) < abs(matrix(j,i))){
                for(int k=0;k<matrix.getColumns();k++){
                    matrix.changeValue(i, k,matrix(i,k)+matrix(j,k));
                    matrix.changeValue(j, k,matrix(i,k)-matrix(j,k));
                    matrix.changeValue(i, k,matrix(i,k)-matrix(j,k));
                }
            }
        }
    }


    for(int i=0;i<matrix.getRows()-1;i++){
        for(int j=i+1;j<matrix.getRows();j++){
            double f = matrix(j,i) / matrix(i,i);
            for(int k=0;k<matrix.getRows()+1;k++){
                matrix.changeValue(j, k,matrix(j,k)-f*matrix(i,k));
            }
        }
    }

    cout << "\n here is matrix after gem";
    matrix.printMatrix();
}

void MatrixHelper::printResults() {
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

    cout<<"\nHere are your results\n";
    cout<<"_____________________\n";
    int index = 0;
    for (double number : matrix.getResultsArray()) {
        cout << "x" <<index << " = " << number <<endl;
        index++;
    }
}
