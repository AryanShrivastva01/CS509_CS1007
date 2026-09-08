#include <algorithm>
#include "B_GEMM.hpp"

using namespace std;

const int BLOCK_SIZE = 2;

void BMM(int M1[MAX][MAX], int M2[MAX][MAX],
         int M3[MAX][MAX],
         int r1, int c1, int c2)
{
    // Initialize result matrix
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            M3[i][j] = 0;

    // Block order: ii -> kk -> jj
    for (int ii = 0; ii < r1; ii += BLOCK_SIZE)
    {
        for (int kk = 0; kk < c1; kk += BLOCK_SIZE)
        {
            for (int jj = 0; jj < c2; jj += BLOCK_SIZE)
            {
                for (int i = ii; i < min(ii + BLOCK_SIZE, r1); i++)
                {
                    for (int k = kk; k < min(kk + BLOCK_SIZE, c1); k++)
                    {
                        // Keep A[i][k] in a register/cache
                        int temp = M1[i][k];

                        for (int j = jj; j < min(jj + BLOCK_SIZE, c2); j++)
                        {
                            M3[i][j] += temp * M2[k][j];
                        }
                    }
                }
            }
        }
    }
}