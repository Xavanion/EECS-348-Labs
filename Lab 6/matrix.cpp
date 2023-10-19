#include <iostream>
#include <fstream>
#include <sstream>

const int MAX_SIZE = 100;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int matrixsize){
    for (int i=0; i < matrixsize; i++){
        for (int n=0; n < matrixsize; n++){
            std::cout << matrix[i][n] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return;
}

void addMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int matrixsize){
    std::cout << "Matrix Sum (A+B)\n";
    for (int i=0; i < matrixsize; i++){
        for (int n=0; n < matrixsize; n++){
            std::cout << (matrixA[i][n] + matrixB[i][n]) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void multiplyMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int matrixsize){
    std::cout << "Matrix Product (A*B)\n";
    for (int i=0; i < matrixsize; i++){
        for (int n=0; n < matrixsize; n++){
            std::cout << (matrixA[i][n] * matrixB[i][n]) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void differenceMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int matrixsize){
    std::cout << "Matrix Difference (A-B)\n";
    for (int i=0; i < matrixsize; i++){
        for (int n=0; n < matrixsize; n++){
            std::cout << (matrixA[i][n] - matrixB[i][n]) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main (){
    //Setup Variables
    int matrixsize;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    std::ifstream infile("matrices.txt");
    //Read First line into variable
    infile >> matrixsize;
    
    //Update Matrice with values
    std::string line;
    int rowIndex = 0;
    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        int val;
        if (rowIndex < 3){
            for (int i = 0; i < matrixsize; i++){
                iss >> val;
                matrixA[rowIndex][i] = val;
            }
        }
        else {
            for (int i = 0; i < matrixsize; i++){
                iss >> val;
                matrixB[(rowIndex-3)][i] = val;
        }
        }
        rowIndex += 1;
        //printf("%s\n", line.c_str());
    }
    infile.close();

    //Matrix Manipulation Functions
    std::cout << "Matrix A\n";
    printMatrix(matrixA, matrixsize);
    std::cout << "Matrix B\n";
    printMatrix(matrixB, matrixsize);
    addMatrix(matrixA, matrixB, matrixsize);
    multiplyMatrix(matrixA, matrixB, matrixsize);
    differenceMatrix(matrixA, matrixB, matrixsize);
    return 0;
}
