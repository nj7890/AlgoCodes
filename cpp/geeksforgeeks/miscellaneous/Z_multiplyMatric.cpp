/*
Program to multiply two matrices

    Given two matrices, the task to multiply them. Matrices can either be square or rectangular.

    Examples:

    Input : mat1[][] = {{1, 2}, 
                       {3, 4}}
            mat2[][] = {{1, 1}, 
                        {1, 1}}
    Output : {{3, 3}, 
              {7, 7}}
    Input : mat1[][] = {{2, 4}, 
                        {3, 4}}
            mat2[][] = {{1, 2}, 
                        {1, 3}}       
    Output : {{6, 16}, 
              {7, 18}}
*/

#include <iostream>
using namespace std;
#define N 100001

void multiplyMatric(int A[][N], int B[][N], int res[][N], int x, int y)
{
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; i < y; ++j)
            res[i][j] += A[i][j] * B[i][j];
    }
}

int main()
{
    int m, n, x, y;

    scanf("%d %d %d %d", &m, &n, &x, &y);

    int A[m][N], B[x][N];
    
    int res[m][N] = {0};

    for (int i = 0; i < n; ++i)
        for (int j = 0; i < n; ++j)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < x; ++i)
        for (int j = 0; i < y; ++j)
            scanf("%d", &B[i][j]);

    if (n == x)
    {
        multiplyMatric(A, B, res, m, y);

        for (int i = 0; i < x; ++i)
            for (int j = 0; i < y; ++j)
                printf("%d", res[i][j]);
    }
    else
    {
        printf("Matrices can't br multiplied!!");
    }

    return 0;
}