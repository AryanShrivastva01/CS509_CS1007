#include <iostream>
#include <fstream>
#include<chrono>
#include "../src/GEMM.hpp"
#include "../src/B_GEMM.hpp"

using namespace std;
using namespace std::chrono;

void printMatrix(int M[MAX][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

 int M1[MAX][MAX];
    int M2[MAX][MAX];

    int CGEMM[MAX][MAX];
    int CB_GEMM[MAX][MAX];
int main(){
   ifstream fin("tests/input_03_1024.txt");
    if (!fin.is_open()) {
    cout << "File not found!" << endl;
    return 0;
}

    int r1, c1, r2, c2;
    fin >> r1 >> c1;

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            fin >> M1[i][j];}
        }

    fin >> r2 >> c2;
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            fin >> M2[i][j];}
        }
    fin.close();

    if(c1 != r2)
    {
        cout << "Matrix multiplication not possible" << endl;
        return 0;
    }

// Code For GEMM Matrix Multiplication
auto startGEMM = high_resolution_clock::now();
GEMM(M1, M2, CGEMM, r1, c1, c2);
auto stopGEMM = high_resolution_clock::now();
auto durationGEMM = duration_cast<microseconds>(stopGEMM - startGEMM);

// Code For B_GEMM Matrix Multiplication
auto startB_GEMM = high_resolution_clock::now();
BMM(M1, M2, CB_GEMM, r1, c1, c2);
auto stopB_GEMM = high_resolution_clock::now();
auto durationBMM = duration_cast<microseconds>(stopB_GEMM - startB_GEMM);

    cout << "Result using GMM:" << endl;

    printMatrix(CGEMM, r1, c2);
    cout << "GEMM Execution Time: "<< durationGEMM.count()<< " microseconds" << endl;
    cout << endl;

    cout << "Result using B_GEMM:" << endl;
    printMatrix(CB_GEMM, r1, c2);

    cout << "BMM Execution Time: "<< durationBMM.count() << " microseconds" << endl;
    return 0;
}
