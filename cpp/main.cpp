#include <iostream>
#include <memory>
#include <vector>
#include "project.cpp"
#include "bfs.h"
#define N 3
// #include "project.h"




int main()
{



int matrix[N][N] ;
int goal_matrix[N][N] ; 
int Get ;
std::cout << "Please enter your first puzzle" << std::endl ;  
for (size_t i{0} ; i < N; i++)
{
    for (size_t j{0} ; j < N; j++)
    {
        std::cin >>  matrix[i][j] ;
    }
    
}
std::cout << "Please enter goal matrix" << std::endl ; 
for (size_t i{0} ; i < N; i++)
{
    for (size_t j{0} ; j < N; j++)
    {
        std::cin >>  goal_matrix[i][j] ;
    }
    
}
bfs a{matrix} ; 
disp_matrix(matrix) ; 
solve_bfs(a , goal_matrix , matrix) ; 
// std::vector<int> a  ; 
// int d = 5 ;  
// a.push_back(d) ;
// d = 7 ; 
// a.push_back(d); 
// std::cout << a[0] << a[1] << std::endl ;
return 0 ; 

}