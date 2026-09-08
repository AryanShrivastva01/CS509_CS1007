#include "GEMM.hpp"

void GEMM(int M1[MAX][MAX], int M2[MAX][MAX],int M3[MAX][MAX] , int r1, int c1, int c2)
{
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            M3[i][j] = 0;
            for(int k = 0; k < c1; k++)
            {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}