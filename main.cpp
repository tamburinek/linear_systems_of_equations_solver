#include<iostream>
#include "Matrix.h"
#include "MatrixHelper.h"
#include <fstream>
using namespace std;

template <typename TimePoint>
std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}

vector<vector<long double> > takeDataFromUser(int n){
    cout<<"\nEnter the numbers you want to count: " << endl;
    vector<vector<long double> > initialData;
    for(int i=0;i<n;i++){
        long double helper;
        vector<long double> array;

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

    if (argc > 1){
        if (strcmp(argv[1],"--help") == 0){
            cout << "\nThis app solves system of linear equations \n"
                    "It solves it only in one thread \n"
                    "But that does not mean that it is useless :/ \n"
                    "---------------------------\n"
                    "Commands: \n"
                    "You found this, so you know command --help \n"
                    "But you can also use command --file "
                    "which sets app to read from file mode\n"
                    "After that you just have to write file name. \n"
                    "If you start app without any command - app will be in Take Data From User status\n"
                    "If you start app with unknown command it will stop without result\n"
                    "That is all for commands. \n"
                    "---------------------------\n"
                    "So this is how app works: \n"
                    "It takes data from user or file \n"
                    "After that it prints the matrix in equation shape \n"
                    "Then it makes some magic (it makes GEM) \n"
                    "After GEM it prints Matrix in equation shape again \n"
                    "Then it just prints the results \n";


            return 0;
        }
        else if (strcmp(argv[1], "--file") == 0){
            solveFromFile = true;
        }
        else {
            cout << "\nI dont know this command - we are finished here\n";
            return 0;
        }
    }

    int n;
    vector<vector<long double> > matrixData;

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
            if (n <= 1){
                cout << "\nI am sorry but no jokes with me! Text just said that u dont have variables. Not cool.\n";
                return 0;
            }
            cout << "Number of variables is " << n;
            vector<vector<long double> > initialData;
            for(int i=0;i<n;i++){
                long double helper;
                vector<long double> array;

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
