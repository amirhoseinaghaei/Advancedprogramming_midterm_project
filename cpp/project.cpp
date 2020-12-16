#include <iostream>
#include "project.h"
#include <cmath>
#include <vector>
//#include <windows.h>

#define N 3

typedef struct greaterSmaller Struct;

int k =0 ;  

std::vector<bfs> check_stop_bfs ; 


void disp_matrix(int matrix[N][N])
{
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void solve_bfs(bfs a, int gm[N][N], int m[N][N])
{
    

    if (is_final(m, gm) == true)
    {
        std::cout << "Here is the matrix" << std::endl;
        disp_matrix(m);
       k = 1 ; 
    }
    else
    {
        std::cout << "Hello" << std::endl;
        create_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);

        // disp_matrix(a.childs[0].matrix) ;
    }

    //
    // for (size_t i{0}; i < a.childs.size(); i++)
    // {
    //     create_child(a.childs[i] ,find_zero_location(a.childs[i]).x ,find_zero_location(a.childs[i]).y )
    // }

    // int var_mat[N][N];
    // for (size_t i{0}; i < N; i++)
    // {
    //     for (size_t j{0}; j < N; j++)
    //     {
    //         var_mat[i][j] = m[i][j];
    //         if (m[i][j] == 0)
    //         {
    //             i_C = i;
    //             j_C = j;
    //         }
    //     }
    // }
    // // disp_matrix(var_mat);
    // //std::cout << i_C << j_C << std::endl;
    // while (true)
    // {
    //     if (check_f = true)
    //     {
    //         break;
    //     }
    //     else
    //     {

    //     }

    // }

    //     break  ;
    // }
}

void create_child(bfs a, int I_C, int J_C, int gm[N][N])
{
    
    // if (is_final(a.childs[i].matrix, gm) == true)
    // {
    //     std::cout << "Here is the matrix " << std::endl;
    // }

    for (int i{0}; i < N; i++)
    {
        for (int j{0}; j < N; j++)
        {

            if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
            {
            
                int crowl_mat[N][N];
                set_equal(crowl_mat, a.matrix);
                std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
                if (k != 1 )
                 {
                   
                // // disp_matrix(crowl_mat);
                if (is_in_list(crowl_mat) == false)
                 {
                 bfs *crow = new bfs;
                 crow = &a;
                 bfs New{bfs(crow, crowl_mat)};
                 disp_matrix(New.matrix);
                 std::cout << "amiramir amir" << std::endl ;
                 
                      add_to_list(New) ; 
                      a.childs.push_back(New);
                     solve_bfs(New,gm, New.matrix);
                      crow = nullptr;
                 }
                 
                 }
                //
                // {   
                //     add_to_list(New) ; 
                //     a.childs.push_back(New);
                //     // disp_matrix(New.matrix);
                //      std::cout << "*****************" << std::endl ;
                //      disp_matrix(gm);
                //      std::cout << "*****************" << std::endl ;
                //      //Sleep(1000);
                //     solve_bfs(New,gm, New.matrix);
                //     // disp_matrix(a.childs[i].matrix);
                //    
                // }
            }
        }
    }
}

bool is_final(int m[N][N], int gm[N][N])
{
    bool check = true;
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {

            if (m[i][j] != gm[i][j])
            {
                check = false;
            }
        }
    }
    return check;
}

Struct find_zero_location(bfs a)
{
    Struct s;
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {

            if (a.matrix[i][j] == 0)
            {
                s.x = i;
                s.y = j;
            }
        }
    }
    return s;
}

void set_equal(int wanted_mat[N][N], int from_mat[N][N])
{
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {

            wanted_mat[i][j] = from_mat[i][j];
        }
    }
}


void add_to_list(bfs inp)
{
    check_stop_bfs.push_back(inp) ; 
}



bool is_in_list(int inp[N][N])
{
    for (size_t i{0}; i < check_stop_bfs.size(); i++)
    {
       if (is_final(check_stop_bfs[i].matrix , inp) == true)
       {
           check_stop_bfs.clear();
           return true ; 
           break  ;
       }
       else
       {
           return false ; 
       }
       
    }
}