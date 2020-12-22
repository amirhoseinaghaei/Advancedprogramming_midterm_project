#include <iostream>
#include <memory>
#include <vector>
#include "project.cpp"
// #include "dfs.h"
// #include "dfs.cpp"
#include "bfs.h"
#define N 3
// #include "project.h"




int main()
{



// std::vector<int> a ;
// a.push_back(2) ; 
// a.push_back(3) ; 
// a.push_back(4) ; 
// a.push_back(5) ; 
// a.push_back(6) ; 
// a.push_back(7) ; 
//  std::find(a.begin(), a.end(), 6) != a.end() ;
//  if ( std::find(a.begin(), a.end(), 10) != a.end() )
//   {
//       std::cout << "amir"<< std::endl  ;
//   }

int matrix[N][N] ;
int goal_matrix[N][N] ; 

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
//check_stop_bfs.push_back(a);
disp_matrix(matrix) ; 
disp_matrix(goal_matrix) ; 
check_stop_bfs.push_back(to_id(matrix));
solve_dfs(a , to_id(goal_matrix) , matrix, to_id(matrix)) ; 
 
// std::vector<int> a  ; 
// int d = 5 ;  
// a.push_back(d) ;
// d = 7 ; 
// a.push_back(d); 
// std::cout << a[0] << a[1] << std::endl ;
return 0 ; 

}