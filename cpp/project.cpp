#include <iostream>
#include "project.h"
#include <cmath>
#include <vector>

#define N 3

typedef struct greaterSmaller Struct;

int k = 0;

std::vector<int> check_stop_bfs;

void solve_bfs(bfs a, int gm[N][N], int m[N][N])
{

    if (is_final(m, gm) == true)
    {
        std::cout << "Here is the matrix" << std::endl;
        disp_matrix(m);
        k++;
    }
    else
    {
        std::cout << "Hello" << std::endl;
        disp_matrix(a.matrix);
        create_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    }
}

int create_child(bfs a, int I_C, int J_C, int gm[N][N])
{

    std::cout << "io" << std::endl;

   
        for (int i{0}; i < N; i++)
        {
            for (int j{0}; j < N; j++)
            {

                if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
                {

                    int crowl_mat[N][N];
                    set_equal(crowl_mat, a.matrix);
                    std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
                    int id = to_id(crowl_mat);
                    // // disp_matrix(crowl_mat);
                    std::cout << "****" << check_stop_bfs.size() << "****" << std::endl;
                    //std::cout << "****" << is_in_list(crowl_mat) << "****" << std::endl;
                    if (is_in_list(id) == false)
                    {
                        // bfs *crow = new bfs;
                        // crow = &a;
                        bfs New{bfs(crowl_mat)};
                        disp_matrix(New.matrix);
                        std::cout << "amiramir amir" << std::endl;
                        std::cout << k << std::endl ;
                        add_to_list(id);

                        //  a.childs.push_back(New);
                        std::cout << "amiramir amir" << std::endl;
                        solve_bfs(New, gm, crowl_mat);
                        // crow = nullptr;
                    }
                }
            }
        }
    

    return 0;
    // }
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
    std::cout << "j" << std::endl;
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

void add_to_list(int inp)
{
    check_stop_bfs.push_back(inp);
}

bool is_in_list(int inp)
{

    for (size_t i{0}; i < check_stop_bfs.size(); i++)
    {
        if (inp == check_stop_bfs[i])
        //  if (inp[1][1]  == 3)
        {
            //
            return true;
        }
        else
        {
            return false;
        }
    }
}

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

int to_id(int mat[N][N])
{
    int id = 0;
    size_t p = 8;
    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {

            id = id + (mat[i][j] * (std::pow(10, p)));
            p--;
        }
    }

    return id;
}
