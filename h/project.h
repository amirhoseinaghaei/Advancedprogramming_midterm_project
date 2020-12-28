#if !defined(PROJECT_H)
#define PROJECT_H
#include <iostream>
#define N 3 
#include "Node.h"
#include <vector>
#include <memory>



std::vector<int> check_stop_Node;
std::vector<int> check_stop_Node_without_limit;
std::vector<int> check_stop;
std::vector<int> check_stop_b;
std::vector<int> check_stop_f;
std::vector<int> disp_vec ; 
std::vector<int> biodirectal_f ; 
std::vector<int> biodirectal_b ; 
struct greaterSmaller { 
    int x, y; 
}; 
  
typedef struct greaterSmaller Struct; 
void disp_matrix(int matrix[N][N]) ;
bool is_final(int m[N][N], int gm[N][N]);
Struct find_zero_location(Node& a);
void set_equal(int wanted_mat[N][N] , int from_mat[N][N]); 
int solve_dfs(Node& a , int gm,int m[N][N] , int source , int depth) ; 
int solve_Node(Node& a, int gm[N][N], int m[N][N], int source , int depth);
std::vector<std::shared_ptr<Node>> create_Node_child(Node& a, int I_C, int J_C, int gm[N][N]);
bool isSolvable(int puzzle[3][3])  ; 
int getInvCount(int arr[]) ;
std::vector<std::shared_ptr<Node>> create_dfs_child(Node& a, int I_C, int J_C , int gm) ;
int solve_biodirectal(Node &a , Node&b, int gm[N][N], int m[N][N], int source_f , int source_b) ;
std::vector<std::shared_ptr<Node>> create_Node_child_f(Node &a, int I_C, int J_C, int gm[N][N]);
std::vector<std::shared_ptr<Node>> create_Node_child_b(Node &a, int I_C, int J_C, int gm[N][N]);
int solve_dfs_without_limit(Node &a, int gm, int m[N][N], int source);
std::vector<std::shared_ptr<Node>> create_dfs_child_without_limit(Node &a, int I_C, int J_C, int gm);
auto to_matrix(int id) ;
// bool is_in_list(int inp ) ;
 // void add_to_list(int inp) ;
int to_id(int mat[N][N]);
void disp() ;
bool is_id_final (int a , int b); 
#endif // PROJECT_H



