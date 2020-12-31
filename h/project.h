#if !defined(PROJECT_H)
#define PROJECT_H
#include <iostream>
#include "Node.h"
#include <vector>
#include <memory>



struct greaterSmaller
{
    int x, y;
};

typedef struct greaterSmaller Struct;
void disp_matrix(int matrix[3][3]);
bool is_final(int m[3][3], int gm[3][3]);
Struct find_zero_location(Node &a);
void set_equal(int wanted_mat[3][3], int from_mat[3][3]);
int solve_dfs(Node &a, int gm, int m[3][3], int source, int depth);
int solve_bfs(Node &a, int gm[3][3], int m[3][3], int source, int depth);
std::vector<std::shared_ptr<Node>> create_bfs_child(Node &a, int I_C, int J_C, int gm[3][3]);
bool isSolvable(int puzzle[3][3]);
int getInvCount(int arr[]);
std::vector<std::shared_ptr<Node>> create_dfs_child(Node &a, int I_C, int J_C, int gm);
int solve_bidirectional(Node &a, Node &b, int gm[3][3], int m[3][3], int source_f, int source_b, int depth);
std::vector<std::shared_ptr<Node>> create_bfs_child_f(Node &a, int I_C, int J_C, int gm[3][3]);
std::vector<std::shared_ptr<Node>> create_bfs_child_b(Node &a, int I_C, int J_C, int gm[3][3]);
int solve_dfs_without_limit(Node &a, int gm, int m[3][3], int source);
std::vector<std::shared_ptr<Node>> create_dfs_child_without_limit(Node &a, int I_C, int J_C, int gm);
auto to_matrix(int id);
int to_id(int mat[3][3]);
void disp();
bool is_id_final(int a, int b);

#endif // PROJECT_H
