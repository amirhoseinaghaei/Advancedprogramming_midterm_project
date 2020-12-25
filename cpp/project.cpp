#include <iostream>
#include "project.h"
#include "bfs.h"
#include <cmath>
#include <vector>
#include <ctime>
#include <memory>

#define N 3
typedef struct greaterSmaller Struct;

int solve_bfs(bfs &a, int gm[N][N], int m[N][N] , int source , int depth)
{
    int func_depth ;
    func_depth = 0 ; 
    std::vector<std::shared_ptr<bfs>> this_row_child = create_bfs_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    std::vector<std::shared_ptr<bfs>> this_row_child_next;
    if (is_final(m, gm) == true)
    {

        std::cout << "Here is the matrix" << std::endl;
        disp_matrix(m);
    }
    else
    {
        while (true)
        {
            this_row_child_next.clear();
            // std::time_t start = time(0);
            // while( difftime(std::time(0), start) <=4);
            for (size_t i{0}; i < this_row_child.size(); i++)
            {
                //   disp_matrix(this_row_child[i].matrix);
                if (is_final(this_row_child[i]->matrix, gm) == true)
                {

                    std::cout << "Here is the matrix" << std::endl;
                    disp_matrix(this_row_child[i]->matrix);

                    std::vector<bfs *> answer_list;
                    bfs *disp;

                    disp = this_row_child[i].get();
                    answer_list.push_back((disp));
                    while (true)
                    {
                        if (is_id_final(to_id(disp->matrix), source))
                        {
                            break;
                        }
                        answer_list.push_back((disp->parent));

                        disp = disp->parent;
                    }
                    std::reverse(std::begin(answer_list), std::end(answer_list));
                    //  std::cout << "hello" << std::endl;
                    for (size_t i{0}; i < answer_list.size(); i++)

                    {
                        std::time_t start = time(0);
                        while (difftime(std::time(0), start) <= 1)
                            ;
                        //   "2 - Custom source with default goal"
                        std::cout << "\033[94;1m" << i << ":"
                                  << "\033[0m" << std::endl;
                        std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                        disp_matrix(answer_list[i]->matrix);
                        std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    }

                    return 0;
            
                    
                
                
                }
                else
                {
                    std::vector<std::shared_ptr<bfs>> this_row_child_next_crowler = create_bfs_child(*this_row_child[i], find_zero_location(*this_row_child[i]).x, find_zero_location(*this_row_child[i]).y, gm);

                    for (size_t i{0}; i < this_row_child_next_crowler.size(); i++)
                    {
                        this_row_child_next.push_back(this_row_child_next_crowler[i]);
                    }
                }
                //  std::cout << "*******************" << std::endl ;
                //  std::cout << this_row_child.size() << std::endl;
                //  std::cout << "*******************" << std::endl ;
            }
            func_depth ++ ;
            if (func_depth >= depth)
            {
                return 0 ; 
            } 
            
            // if (this_row_child_next.size() == 0)
            // {
            //     return 0 ;
            // }
            // std::cout << "hello" << std::endl ;

            // std::cout << this_row_child_next.size() << "********"<< std::endl ;
            this_row_child.clear();
            this_row_child = this_row_child_next;
            //this_row_child_next.clear() ;
            // std::cout <<"88888"<< this_row_child.size() <<"8888"<< std::endl;
        }
    }
}


std::vector<std::shared_ptr<bfs>> create_bfs_child(bfs &a, int I_C, int J_C, int gm[N][N])
{

    std::vector<std::shared_ptr<bfs>> list_child;
   
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
                for (size_t i{0}; i < check_stop.size(); i++)
                {
                    if (id == check_stop[i])
                    {

                        check = true;
                    }
                }
                if (check == false)
                {

                    // bfs *crow = new bfs;
                    // crow = &a;
                    check_stop.push_back(id);
                    // bfs New{bfs(crowl_mat)};

                    // list_child.push_back(New);
                    // a.childs.push_back(New);
                    std::shared_ptr<bfs> New(new bfs(&a, crowl_mat));
                // *New = wq;
                   list_child.push_back(New);
                   a.childs.push_back(New);
                    // crow = nullptr;
                }
            }
        }
    }
    //check_stop_bfs.clear();
    return list_child;
    // }
}

int k = 0;
int depth;
int solve_dfs(bfs &a, int gm, int m[N][N], int source)
{

    std::vector<std::shared_ptr<bfs>> this_row_child = create_dfs_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);

    if (is_id_final(to_id(m), gm) == true)
    {

        std::cout << "Here is the matrix" << std::endl;
        disp_matrix(m);
        return 0;
    }
    // else if (this_row_child.size() == 0)
    // {
    //     depth--;
    //     return 0;
    // }
    else
    {
        // depth++ ;
        for (size_t i{0}; i < this_row_child.size(); i++)
        {

            if (k == 1)
            {
                return 0;
            }
            if (is_id_final(to_id(this_row_child[i]->matrix), gm) == true)
            {
                k = 1;
                //  std::cout << "Here is the answer :" << std::endl;
                std::cout << depth << std::endl;
                //   std::cout << check_stop_bfs.size() << std::endl;
               // disp_matrix(this_row_child[i]->matrix);
                std::vector<bfs *> answer_list;
                int h = 0;
                bfs *disp;

                disp = this_row_child[i].get();
                answer_list.push_back((disp));
                while (true)
                {
                    if (is_id_final(to_id(disp->matrix), source))
                    {
                        break;
                    }
                    answer_list.push_back((disp->parent));

                    disp = disp->parent;
                }
                std::reverse(std::begin(answer_list), std::end(answer_list));
                //  std::cout << "hello" << std::endl;
                for (size_t i{0}; i < answer_list.size(); i++)
                {

                    std::time_t start = time(0);
                    while (difftime(std::time(0), start) <= 1)
                        ;

                    //   "2 - Custom source with default goal"
                    std::cout << "\033[94;1m" << i << ":"
                              << "\033[0m" << std::endl;
                    std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    disp_matrix(answer_list[i]->matrix);
                    std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                }

                return 0;
            }
            else
            {

                // if (depth == 15 )
                // {
                //     depth--;
                //     return 0 ;
                // }
                if (depth < 10)
                {

                    depth++;
                    solve_dfs(*this_row_child[i], gm, this_row_child[i]->matrix, source);
                }
                // else
                // {
                //     depth-- ;
                //     break;
                // }
            }
            // if (i == this_row_child.size() - 1)
            // {
            //     return 0;
            // }
        }
        if (k != 1)
        {
            depth--;
        }
        return 0;
    }
}

std::vector<std::shared_ptr<bfs>> create_dfs_child(bfs &a, int I_C, int J_C, int gm)
{

    std::vector<std::shared_ptr<bfs>> list_child;

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
                //  std::cout << check_stop_bfs.size() << std::endl;
                // for (size_t i{0}; i < check_stop_bfs.size(); i++)
                // {
                //     if (id == check_stop_bfs[i])
                //     {

                //         check = true;
                //     }
                // }
                if (std::find(check_stop_bfs.begin(), check_stop_bfs.end(), id) != check_stop_bfs.end())
                {
                    check = true;
                }
                if (check == false)
                {

                check_stop_bfs.push_back(id);

                // std::shared_ptr<bfs> b(new bfs);
                // *b = a ;

                std::shared_ptr<bfs> New(new bfs(&a, crowl_mat));
                // *New = wq;
                list_child.push_back(New);
                a.childs.push_back(New);
                // crow = nullptr;
                }
            }
        }
    }

    return list_child;
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

Struct find_zero_location(bfs &a)
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
    // for (size_t i{0}; i < N; i++)
    // {
    //     for (size_t j{0}; j < N; j++)
    //     {

    //         wanted_mat[i][j] = from_mat[i][j];
    //     }
    // }
    wanted_mat[0][0] = from_mat[0][0];
    wanted_mat[0][1] = from_mat[0][1];
    wanted_mat[0][2] = from_mat[0][2];
    wanted_mat[1][0] = from_mat[1][0];
    wanted_mat[1][1] = from_mat[1][1];
    wanted_mat[1][2] = from_mat[1][2];
    wanted_mat[2][0] = from_mat[2][0];
    wanted_mat[2][1] = from_mat[2][1];
    wanted_mat[2][2] = from_mat[2][2];
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
            std::cout << "\033[96;1m" << matrix[i][j] << " "
                      << "\033[0m";
        }
        std::cout << std::endl;
    }
}

int to_id(int matrix[N][N])
{
    // int id = 0;
    // size_t p = 8;
    // for (size_t i{0}; i < N; i++)
    // {
    //     for (size_t j{0}; j < N; j++)
    //     {

    //         id = id + (mat[i][j] * (std::pow(10, p)));
    //         p--;
    //     }
    // }

    // return id;
    int id[9];
    id[0] = matrix[0][0];
    id[1] = matrix[0][1];
    id[2] = matrix[0][2];
    id[3] = matrix[1][0];
    id[4] = matrix[1][1];
    id[5] = matrix[1][2];
    id[6] = matrix[2][0];
    id[7] = matrix[2][1];
    id[8] = matrix[2][2];
    int idd = (std::pow(10, 8)) * id[0] + (std::pow(10, 7)) * id[1] + (std::pow(10, 6)) * id[2] + (std::pow(10, 5)) * id[3] + (std::pow(10, 4)) * id[4] + (std::pow(10, 3)) * id[5] + (std::pow(10, 2)) * id[6] + (std::pow(10, 1)) * id[7] + (std::pow(10, 0)) * id[8];
    return idd;
}

bool is_id_final(int a, int b)
{
    return a == b;
}

int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i + 1; j < 9; j++)
            // Value 0 is used for empty space
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}
// This function returns true if given 8 puzzle is solvable.
bool isSolvable(int puzzle[3][3])
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount((int *)puzzle);

    // return true if inversion count is even.
    return (invCount % 2 == 0);
}


auto to_matrix(int id)
{
    int matrix[N][N] ; 
    matrix[0][0] = id /100000000 %10 ; 
    std::cout << matrix[0][0];
    return matrix ; 
} 