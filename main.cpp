#include<iostream>
#include "Matrix.h"
#include "MatrixHelper.h"
#include <fstream>
using namespace std;

template <typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}

vector<vector<double> > takeDataFromUser(int n){
    cout<<"\nEnter the numbers you want to count: " << endl;
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

    bool solveFromFile = false;

    //argument reader
    if (argc > 1){
        if (strcmp(argv[1],"--help") == 0){
            cout << "This app solves system of linear equations \n"
                    "It solves it only in on thread \n"
                    "But that does not mean that it is useless :/ \n";

            //todo write help

            return 0;
        }
        else if (strcmp(argv[1], "--file") == 0){
            solveFromFile = true;
        }
        else {
            cout << "I dont know this command - we are finished here";
            return 0;
        }
    }

    int n;
    vector<vector<double> > matrixData;

    if (solveFromFile){
        cout << "\nWrite name of your file: \n";
        string fileName;
        cin >> fileName;
        string resultFileName = "../textFiles/" + fileName;
        ifstream fileToRead;
        fileToRead.open(resultFileName);

        if (!fileToRead){
            cout << "\nI really tried but i can not open this file\n";
            return 0;
        }
        else{
            cout<<"\nI started reading numbers from file" << endl;
            fileToRead >> n;
            cout << "here is number of rows " << n;
            vector<vector<double> > initialData;
            for(int i=0;i<n;i++){
                double helper;
                vector<double> array;

                for(int j=0;j<n+1;j++){
                    fileToRead >> helper;
                    array.push_back(helper);
                }
                initialData.push_back(array);
                array.clear();
            }
            matrixData = initialData;
            cout<<"\nI ended reading numbers from file" << endl;
        }
    }

    //end of argument reader
    else if (!solveFromFile){
        cout << "\nYou started this app so you now know how to use it \n"
                "If not - stop app and pass argument --help to show guide \n";
        cout<<"\nEnter how many variables u have for me: " << endl;
        cin>>n;
        matrixData = takeDataFromUser(n);
    }

    Matrix matrix(n);
    auto start = std::chrono::high_resolution_clock::now();

    matrix.setValuesBegin(matrixData);
    matrix.printMatrix();
    MatrixHelper helper(matrix);
    helper.doGemSolve();
    helper.calculateResults();
    helper.printResults();

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nNeeded " << to_ms(end - start).count() << " ms to finish.\n";

    return 0;
}
