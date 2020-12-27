#include "Node.h"

#include <iostream>
#define N 3

Node::Node(Node *pr, int mat[3][3])
{

    for (int i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    parent = new Node; 
    *parent = *pr;
}
Node::Node(int mat[N][N])
{

    for (int i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }

}

Node::Node(const Node & cp)
{
    for (int i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            matrix[i][j] = cp.matrix[i][j];
        }
    }
    parent = cp.parent ; 

}
Node::Node()
{
    // std::cout << "Default constructor" << std::endl;
}