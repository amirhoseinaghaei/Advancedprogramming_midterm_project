#if !defined(PROJECT_H)
#define PROJECT_H
#include <iostream>
#define N 3 
#include "bfs.h"
#include <vector>
#include <memory>



std::vector<int> check_stop_bfs;
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
Struct find_zero_location(bfs& a);
void set_equal(int wanted_mat[N][N] , int from_mat[N][N]); 
int solve_dfs(bfs& a , int gm,int m[N][N] , int source) ; 
int solve_bfs(bfs& a, int gm[N][N], int m[N][N], int source , int depth);
std::vector<std::shared_ptr<bfs>> create_bfs_child(bfs& a, int I_C, int J_C, int gm[N][N]);
bool isSolvable(int puzzle[3][3])  ; 
int getInvCount(int arr[]) ;
std::vector<std::shared_ptr<bfs>> create_dfs_child(bfs& a, int I_C, int J_C , int gm) ;
int solve_biodirectal(bfs &a , bfs&b, int gm[N][N], int m[N][N], int source_f , int source_b) ;
std::vector<std::shared_ptr<bfs>> create_bfs_child_f(bfs &a, int I_C, int J_C, int gm[N][N]);
std::vector<std::shared_ptr<bfs>> create_bfs_child_b(bfs &a, int I_C, int J_C, int gm[N][N]);
auto to_matrix(int id) ;
// bool is_in_list(int inp ) ;
 // void add_to_list(int inp) ;
int to_id(int mat[N][N]);
void disp() ;
bool is_id_final (int a , int b); 
#endif // PROJECT_H



