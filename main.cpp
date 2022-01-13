#include<iostream>
#include "Matrix.h"
#include "MatrixHelper.h"
#include <fstream>
using namespace std;

vector<vector<double> > takeDataFromUser(int n){
    vector<vector<double> > initialData;

    for(int i=0;i<n;i++){

        double helper;
        vector<double> array;

        for(int j=0;j<n+1;j++){
            cin >> helper;
            array.push_back(helper);
        }
        initialData.push_back(array);
        array.clear();
    }

    return initialData;
}



int main(int argc, char *argv[]){

    //argument reader
    if (argc > 1){
        if (strcmp(argv[1],"--help") == 0){
            cout << "This app solves system of linear equations \n"
                    "It solves it only in on thread \n"
                    "But that does not mean that it is useless :/ \n";

            //todo write help

            return 0;
        }
        else {
            cout << "I dont know this command - we are finished here";
            return 0;
        }
    }

    //end of argument reader

    int i,j,k,n;

    cout << "\nYou started this app so you now know how to use it \n"
            "If not - stop app and pass argument --help to show guide \n";

    cout<<"\nEnter how many variables u have for me: " << endl;

    cin>>n;

    Matrix matrix(n);

    cout<<"\nEnter the numbers you want to count: " << endl;

    vector<vector<double> > dataFromUser = takeDataFromUser(n);
    matrix.setValuesBegin(dataFromUser);
    matrix.printMatrix();

    MatrixHelper helper(matrix);
    helper.doGemSolve();
    helper.calculateResults();
    helper.printResults();
    return 0;
}
