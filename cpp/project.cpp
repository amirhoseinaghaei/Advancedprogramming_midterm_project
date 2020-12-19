#include <iostream>
#include "project.h"
#include <cmath>
#include <vector>
#include <ctime>

#define N 3

typedef struct greaterSmaller Struct;

int k = 0;

// int solve_bfs(bfs a, int gm[N][N], int m[N][N])
// {

//     std::vector<bfs> this_row_child = create_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
//     std::vector<bfs> this_row_child_next;
//     if (is_final(m, gm) == true)
//     {

//         std::cout << "Here is the matrix" << std::endl;
//         disp_matrix(m);
//     }
//     else
//     {
//         while (true)
//         {
//                  this_row_child_next.clear() ;
//                 // std::time_t start = time(0);
//           // while( difftime(std::time(0), start) <=4);
//             for (size_t i{0}; i < this_row_child.size(); i++)
//             {
//                   disp_matrix(this_row_child[i].matrix);
//                 if (is_final(this_row_child[i].matrix, gm) == true)
//                 {

//                     std::cout << "Here is the matrixxxxxxxxxxxxxxxxxxxxxx" << std::endl;
//                     disp_matrix(this_row_child[i].matrix);
//                     return 0;
//                 }
//                 else
//                 {
//                     std::vector<bfs> this_row_child_next_crowler = create_child(this_row_child[i], find_zero_location(this_row_child[i]).x, find_zero_location(this_row_child[i]).y, gm);

//                     for (size_t i{0}; i < this_row_child_next_crowler.size(); i++)
//                     {
//                         this_row_child_next.push_back(this_row_child_next_crowler[i]);
//                     }
//                 }
//              std::cout << "*******************" << std::endl ;
//              std::cout << this_row_child.size() << std::endl;
//              std::cout << "*******************" << std::endl ;
//             }
//             // if (this_row_child_next.size() == 0)
//             // {
//             //     return 0 ;
//             // }
//             // std::cout << "hello" << std::endl ;

//             // std::cout << this_row_child_next.size() << "********"<< std::endl ;
//             this_row_child.clear() ;
//             this_row_child =  this_row_child_next  ;
//             //this_row_child_next.clear() ;
//             // std::cout <<"88888"<< this_row_child.size() <<"8888"<< std::endl;

//         }
//     }
// }
// std::vector<int> check_stop_bfs;

// std::vector<bfs> create_child(bfs a, int I_C, int J_C, int gm[N][N])
// {

//     std::vector<bfs> list_child;
//     for (int i{0}; i < N; i++)
//     {

//         for (int j{0}; j < N; j++)
//         {

//             if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
//             {

//                 int crowl_mat[N][N];
//                 set_equal(crowl_mat, a.matrix);
//                 std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
//                 int id = to_id(crowl_mat);
//                 bool check = false;
//                 for (size_t i{0}; i < check_stop_bfs.size(); i++)
//                 {
//                     if (id == check_stop_bfs[i])
//                     {

//                         check = true;
//                     }
//                 }
//                 if (check == false)
//                 {

//                     // bfs *crow = new bfs;
//                     // crow = &a;
//                     check_stop_bfs.push_back(id);
//                     bfs New{bfs(crowl_mat)};

//                     list_child.push_back(New);
//                     //  a.childs.push_back(New);
//                     // crow = nullptr;
//                 }
//             }
//         }
//     }
//     //check_stop_bfs.clear();
//     return list_child;
//     // }
// }

int solve_bfs(bfs a, int gm[N][N], int m[N][N])
{

    // std::time_t start = time(0);
    // while (difftime(std::time(0), start) <= 2) ;
    std::vector<bfs> this_row_child = create_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);

    if (is_final(m, gm) == true)
    {

        std::cout << "Here is the matrix" << std::endl;
        disp_matrix(m);
        return 0;
    }
    else
    {
        if (this_row_child.size() == 0)
        {
            std::cout << "amir" << std::endl;
            return 0;
        }

        for (size_t i{0}; i < this_row_child.size(); i++)
        {
            disp_matrix(this_row_child[i].matrix);
            std::cout << "sssss" << std::endl;
            if (is_final(this_row_child[i].matrix, gm) == true)
            {

                std::cout << "Here is the matrixxxxxxxxxxxxxxxxxxxxxx" << std::endl;
                disp_matrix(this_row_child[i].matrix);
                return 0;
            }
            else
            {

                solve_bfs(this_row_child[i], gm, this_row_child[i].matrix);
            }
        }
        return 0;
    }
}
std::vector<int> check_stop_bfs;

std::vector<bfs> create_child(bfs a, int I_C, int J_C, int gm[N][N])
{


    std::vector<bfs> list_child;
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
                bool check = false;
                for (size_t i{0}; i < check_stop_bfs.size(); i++)
                {
                    if (id == check_stop_bfs[i])
                    {

                        check = true;
                    }
                }
                if (check == false)
                {

                    // bfs *crow = new bfs;
                    // crow = &a;
                    check_stop_bfs.push_back(id);
                    bfs New{bfs(crowl_mat)};

                    list_child.push_back(New);
                    //  a.childs.push_back(New);
                    // crow = nullptr;
                }
            }
        }
    }
    //check_stop_bfs.clear();
    return list_child;
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

// void add_to_list(int inp)
// {
//     check_stop_bfs.push_back(inp);
// }

// bool is_in_list(int inp)
// {
//     bool a;

//     for (size_t i{0}; i < check_stop_bfs.size(); i++)
//     {
//         if (inp == check_stop_bfs[i])
//         //  if (inp[1][1]  == 3)
//         {
//             //
//             a = true;
//         }
//         else
//         {
//             a = false;
//             break;
//         }
//     }
//     return a;
// }

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

void disp()
{

    for (size_t i{0}; i < check_stop_bfs.size(); i++)
    {
        std::cout << check_stop_bfs[i] << std::endl;
    }
}