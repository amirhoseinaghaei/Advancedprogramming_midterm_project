#if !defined(PROJECT_H)
#define PROJECT_H
#include <iostream>
#define N 3 
#include "bfs.h"


struct greaterSmaller { 
    int x, y; 
}; 
  
typedef struct greaterSmaller Struct; 
void disp_matrix(int matrix[N][N]) ;
void solve_bfs(bfs a , int gm[N][N] ,int m[N][N] ) ; 
bool is_final(int m[N][N], int gm[N][N]);
Struct find_zero_location(bfs a);
void set_equal(int wanted_mat[N][N] , int from_mat[N][N]); 
void create_child(bfs a, int I_C, int J_C , int gm[N][N]) ;
bool is_in_list(int inp[N][N] ) ;
void add_to_list(bfs inp) ;
#endif // PROJECT_H



