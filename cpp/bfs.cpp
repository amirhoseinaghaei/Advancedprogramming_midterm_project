#include "bfs.h"

#include <iostream>
#define N 3 

bfs::bfs(bfs *pr , int mat[3][3])
{
    std::cout << "One argument  constructor" << std::endl;
  //  matrix = mat;
    parent = new bfs;
    parent = pr;
}
bfs::bfs(int mat[N][N])
{

    std::cout << "One argument  constructor" << std::endl;
    for (int i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    parent = new bfs;
    parent = this;
}
bfs::bfs()
{
    std::cout << "Default constructor" << std::endl;
}