#if !defined(PROJECT_H)
#define PROJECT_H
#include <iostream>
#define N 3 
#include "bfs.h"
#include <vector>

struct greaterSmaller { 
    int x, y; 
}; 
  
typedef struct greaterSmaller Struct; 
void disp_matrix(int matrix[N][N]) ;
int solve_bfs(bfs a , int gm[N][N] ,int m[N][N] ) ; 
bool is_final(int m[N][N], int gm[N][N]);
Struct find_zero_location(bfs a);
void set_equal(int wanted_mat[N][N] , int from_mat[N][N]); 
std::vector<bfs> create_child(bfs a, int I_C, int J_C , int gm[N][N]) ;
// bool is_in_list(int inp ) ;
// void add_to_list(int inp) ;
int to_id(int mat[N][N]);
void disp() ;
#endif // PROJECT_H



