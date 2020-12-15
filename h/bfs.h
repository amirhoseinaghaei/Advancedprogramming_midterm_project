#if !defined(BFS_H)
#define BFS_H

#define N 3
#include <iostream>
#include <vector>
class bfs
{
public:
    bfs(); 
    bfs(bfs *pr, int mat[N][N]);
    bfs(int mat[N][N]);
    bfs(const bfs & cp);
    
    // stores the parent node of the current node
    // helps in tracing path when the answer is found
    bfs *parent;
    int matrix[N][N];
    std::vector<bfs> childs ; 
    // std::vector<int[N][N]>
};

#endif