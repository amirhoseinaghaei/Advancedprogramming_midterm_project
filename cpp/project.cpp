#include <iostream>
#include "project.h"
#include <cmath>

#define N 3

typedef struct greaterSmaller Struct;

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
    bfs input_bfs{a};

    if (is_final(m, gm) == true)
    {
        std::cout << "Here is the matrix" << std::endl;
         disp_matrix(mat) ;
    }
    else
    {
        std::cout << "Hello" << std::endl ; 
        //std::cout << find_zero_location(a).x << find_zero_location(a).y << std::endl;
        create_child(a , find_zero_location(a).x , find_zero_location(a).y);
       
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

void create_child(bfs a, int I_C, int J_C)
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
                int crowl_mat[N][N] ; 
                set_equal(crowl_mat , a.matrix);
                std::swap(crowl_mat[i][j] , crowl_mat[I_C][J_C]);
                bfs *crow = new bfs;
                crow = &a;
                a.childs.push_back(bfs(crow, crowl_mat));
                disp_matrix(a.childs[].matrix);
                crow = nullptr;
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

void set_equal(int wanted_mat[N][N] , int from_mat[N][N])
{
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {

           wanted_mat[i][j] = from_mat[i][j];
        }
    }
}