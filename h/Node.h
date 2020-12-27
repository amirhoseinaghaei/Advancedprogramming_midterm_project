#if !defined(Node_H)
#define Node_H

#define N 3
#include <iostream>
#include <vector>
#include <memory>
class Node
{
public:
    Node();
    Node(Node *pr, int mat[N][N]);
    Node(int mat[N][N]);
    Node(const Node &cp);
    Node * parent ;
    int matrix[N][N];
    std::vector< std::shared_ptr<Node>> childs;
};

#endif