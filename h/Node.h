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

    // stores the parent node of the current node
    // helps in tracing path when the answer is found
    // std::shared_ptr<Node> parent;
    Node * parent ;
    int matrix[N][N];
    std::vector< std::shared_ptr<Node>> childs;
    // std::vector<int[N][N]>
};

#endif