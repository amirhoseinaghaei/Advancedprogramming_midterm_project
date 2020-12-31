#if !defined(Node_H)
#define Node_H

#include <iostream>
#include <vector>
#include <memory>
class Node
{
public:
    Node();
    ~Node() ; 
    Node(Node *pr, int mat[3][3]);
    Node(int mat[3][3]);
    Node(const Node &cp);
    Node * parent ;
    int matrix[3][3];
    std::vector< std::shared_ptr<Node>> childs;
};

#endif