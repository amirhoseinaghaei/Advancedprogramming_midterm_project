#if !defined(PROJECT_H)
#define PROJECT_H
#include <iostream>
#define N 3 
#include "bfs.h"
#include <vector>
#include <memory>



std::vector<int> check_stop_bfs;

struct greaterSmaller { 
    int x, y; 
}; 
  
typedef struct greaterSmaller Struct; 
void disp_matrix(int matrix[N][N]) ;
bool is_final(int m[N][N], int gm[N][N]);
Struct find_zero_location(bfs& a);
void set_equal(int wanted_mat[N][N] , int from_mat[N][N]); 
int solve_dfs(bfs& a , int gm,int m[N][N] , int source) ; 
int solve_bfs(bfs& a, int gm[N][N], int m[N][N]) ;
std::vector<bfs> create_bfs_child(bfs& a, int I_C, int J_C, int gm[N][N]);
bool isSolvable(int puzzle[3][3])  ; 
int getInvCount(int arr[]) ;
std::vector<std::shared_ptr<bfs>> create_dfs_child(bfs& a, int I_C, int J_C , int gm) ;
// bool is_in_list(int inp ) ;
 // void add_to_list(int inp) ;
int to_id(int mat[N][N]);
void disp() ;
bool is_id_final (int a , int b); 
#endif // PROJECT_H



