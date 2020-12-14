#include <iostream>
#include "project.h"
#include <cmath>

#define N 3

void disp_matrix(int matrix[N][N])
{
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void solve_bfs(bfs a, int gm[N][N], int m[N][N])
{
    int i_C;
    int j_C;
    // if ( gm[0][0] == m[0][0])
    // {
    //     std::cout << "True" << std::endl ;
    // }
    // while (true)
    // {
    std::cout << "amir " << std::endl;
    int var_mat[N][N];
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            var_mat[i][j] = m[i][j];
            if (m[i][j] == 0)
            {
                i_C = i;
                j_C = j;
            }
        }
    }
    disp_matrix(var_mat);
    std::cout << i_C << j_C << std::endl;
    while (true)
    {
        for (int i{0}; i < N; i++)
        {
            for (int j{0}; j < N; j++)
            {
               
                if ( std::abs(i - i_C) + std::abs(j - j_C) == 1)
                {
                   
                    std::cout << i << j << std::endl ;
                }
            }
        }
        break ;
    }

    //     break  ;
    // }
}