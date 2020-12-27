#include "Node.h"

#include <iostream>
#define N 3

Node::Node(Node *pr, int mat[3][3])
{
    // std::cout << "One argument  constructor" << std::endl;
    //  matrix = mat;
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

    // std::cout << "One argument  constructor" << std::endl;
    for (int i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    }
    // parent = new Node;
    // parent = this;
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