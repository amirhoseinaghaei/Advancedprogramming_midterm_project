#include <iostream>
#include "project.h"
#include "Node.h"
#include <cmath>
#include <vector>
#include <ctime>
#include <memory>
#include <iomanip>

#define N 3
typedef struct greaterSmaller Struct;

int solve_Node(Node &a, int gm[N][N], int m[N][N], int source, int depth)
{
    int func_depth;
    func_depth = 0;
    std::vector<std::shared_ptr<Node>> this_row_child = create_Node_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    std::vector<std::shared_ptr<Node>> this_row_child_next;
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

                    std::vector<Node *> answer_list;
                    Node *disp;

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
                     //   std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                        disp_matrix(answer_list[i]->matrix);
                     //   std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    }

                    return 0;
                }
                else
                {
                    std::vector<std::shared_ptr<Node>> this_row_child_next_crowler = create_Node_child(*this_row_child[i], find_zero_location(*this_row_child[i]).x, find_zero_location(*this_row_child[i]).y, gm);

                    for (size_t i{0}; i < this_row_child_next_crowler.size(); i++)
                    {
                        this_row_child_next.push_back(this_row_child_next_crowler[i]);
                    }
                }
                //  std::cout << "*******************" << std::endl ;
                //  std::cout << this_row_child.size() << std::endl;
                //  std::cout << "*******************" << std::endl ;
            }
            func_depth++;
            if (func_depth >= depth)
            {
                return 0;
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

std::vector<std::shared_ptr<Node>> create_Node_child(Node &a, int I_C, int J_C, int gm[N][N])
{

    std::vector<std::shared_ptr<Node>> list_child;

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

                    // Node *crow = new Node;
                    // crow = &a;
                    check_stop.push_back(id);
                    // Node New{Node(crowl_mat)};

                    // list_child.push_back(New);
                    // a.childs.push_back(New);
                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    // *New = wq;
                    list_child.push_back(New);
                    a.childs.push_back(New);
                    // crow = nullptr;
                }
            }
        }
    }
    //check_stop_Node.clear();
    return list_child;
    // }
}

int k = 0;
int depth = 0;
int solve_dfs(Node &a, int gm, int m[N][N], int source)
{

    // if (check_stop_Node.size() == 1)
    // {
    //         depth++ ;
    // }

    std::vector<std::shared_ptr<Node>> this_row_child = create_dfs_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
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

        for (size_t i{0}; i < this_row_child.size(); i++)
        {

            if (k == 1)
            {
                return 0;
            }
            if (is_id_final(to_id(this_row_child[i]->matrix), gm) == true)
            {
                k = 1;
                std::cout << "Here is the answer :" << std::endl;
                std::cout << depth << std::endl;
                std::cout << check_stop_Node.size() << std::endl;
                // disp_matrix(this_row_child[i]->matrix);
                std::vector<Node *> answer_list;
                int h = 0;
                Node *disp;

                disp = this_row_child[i].get();
                //  answer_list.push_back((disp));
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
                    //  std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    disp_matrix(answer_list[i]->matrix);
                    //  std::cout << "\033[92;1m***********************\033[0m" << std::endl;
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
                // std::cout << depth << std::endl ;

                if (depth < 15)
                {

                    depth++;
                    // std::cout << this_row_child.size() << std::endl ;
                    solve_dfs(*this_row_child[i], gm, this_row_child[i]->matrix, source);
                }
            }
            // if (i == this_row_child.size() - 1)
            // {
            //     return 0;
            // }
        }
        // if (k != 1)
        // {

        check_stop_Node.resize(check_stop_Node.size() - this_row_child.size());

        depth--;
        // }
        // 630285147
    }
    return 0;
}

std::vector<std::shared_ptr<Node>> create_dfs_child(Node &a, int I_C, int J_C, int gm)
{

    std::vector<std::shared_ptr<Node>> list_child;

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
                //  std::cout << check_stop_Node.size() << std::endl;
                // for (size_t i{0}; i < check_stop_Node.size(); i++)
                // {
                //     if (id == check_stop_Node[i])
                //     {

                //         check = true;
                //     }
                // }
                if (std::find(check_stop_Node.begin(), check_stop_Node.end(), id) != check_stop_Node.end())
                {
                    check = true;
                }
                if (check == false)
                {

                    check_stop_Node.push_back(id);

                    // std::shared_ptr<Node> b(new Node);
                    // *b = a ;

                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
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

Struct find_zero_location(Node &a)
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
//     check_stop_Node.push_back(inp);
// }

// bool is_in_list(int inp)
// {
//     bool a;

//     for (size_t i{0}; i < check_stop_Node.size(); i++)
//     {
//         if (inp == check_stop_Node[i])
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
    std::cout << "\033[90;1;100m"
              << "--------------------------"
              << "\033[0m" << std::endl;

    for (size_t i{0}; i < N; i++)
    {
        for (size_t j{0}; j < N; j++)
        {
            if (j == 0)
            {
                if (matrix[i][j] == 0)
                {
                    std::cout << "\033[90;1;100m" << std::setw(2) << "|"
                              << "\033[0m"
                              << "\033[96;1;101m" << std::setw(5) << (matrix[i][j]) << " "
                              << "\033[0m"
                              << "\033[90;1;100m" << std::setw(2)  << "|"
                              << "\033[0m";
                }

                else
                {
                    std::cout << "\033[90;1;100m" << std::setw(2) << "|"
                              << "\033[0m"
                              << "\033[96;1;103m" << std::setw(5) << (matrix[i][j]) << " "
                              << "\033[0m"
                              << "\033[90;1;100m" << std::setw(2) << "|"
                              << "\033[0m";
                }
            }

            else
            {
                if (matrix[i][j] == 0)
                {
                    std::cout << "\033[96;1;101m" << std::left << std::setw(5) << matrix[i][j] << " "
                              << "\033[0m"
                              << "\033[90;1;100m" << std::setw(2) << "|"
                              << "\033[0m";
                }
                else
                {

                    std::cout << "\033[96;1;103m" << std::left << std::setw(5) << matrix[i][j] << " "
                              << "\033[0m"
                              << "\033[90;1;100m" << std::setw(2) << "|"
                              << "\033[0m";
                }
            }

            // std::cout<< std::endl;
            // std::cout << "*" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "\033[90;1;100m"
                  << "--------------------------"
                  << "\033[0m" << std::endl;
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
    int matrix[N][N];
    matrix[0][0] = id / 100000000 % 10;
    std::cout << matrix[0][0];
    return matrix;
}

int solve_biodirectal(Node &a , Node&b, int gm[N][N], int m[N][N], int source_f , int source_b)
{

    std::vector<std::shared_ptr<Node>> this_row_child_1 = create_Node_child_b(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    std::vector<std::shared_ptr<Node>> this_row_child_next_1;
   std::vector<std::shared_ptr<Node>> this_row_child_2 = create_Node_child_f(b, find_zero_location(b).x, find_zero_location(b).y, m);
   std::vector<std::shared_ptr<Node>> this_row_child_next_2;
    if (is_final(a.matrix, b.matrix) == true)
    {

        std::cout << "Here is the matrix" << std::endl;
        disp_matrix(m);
        return 0 ;
    }
    else
    {
         while (true)
        {
          //  this_row_child_next_1.clear();
           // this_row_child_next_2.clear();

            for (size_t i{0}; i < this_row_child_1.size(); i++)
            {
                
                  
                 
                    std::vector<std::shared_ptr<Node>> this_row_child_next_crowler_1 = create_Node_child_b(*this_row_child_1[i], find_zero_location(*this_row_child_1[i]).x, find_zero_location(*this_row_child_1[i]).y, gm);

                    for (size_t i{0}; i < this_row_child_next_crowler_1.size(); i++)
                    {
                        this_row_child_next_1.push_back(this_row_child_next_crowler_1[i]);
                    }
                

            }
            for (size_t i{0}; i < this_row_child_2.size(); i++)
            {
                
                    std::vector<std::shared_ptr<Node>> this_row_child_next_crowler_2 = create_Node_child_f(*this_row_child_2[i], find_zero_location(*this_row_child_2[i]).x, find_zero_location(*this_row_child_2[i]).y, gm);

                    for (size_t i{0}; i < this_row_child_next_crowler_2.size(); i++)
                    {
                        this_row_child_next_2.push_back(this_row_child_next_crowler_2[i]);
                    }
                
           }
            // }
            for (size_t i = 0; i < this_row_child_1.size(); i++)
            {
                for (size_t j = 0; j < this_row_child_2.size(); j++)
                {
                    if (is_id_final(to_id(this_row_child_2[j]->matrix),to_id(this_row_child_1[i]->matrix)) == true)
                    {
                        std::cout << "YYYYYYYYYYYYYY" << std::endl ;
                        std::cout << to_id(this_row_child_2[j]->matrix) << std::endl ; 
                        std::cout << to_id(this_row_child_1[i]->matrix) << std::endl ; 
                        
                    std::vector<Node *> answer_list_1;
                    Node *disp_1;
                        
                    std::vector<Node *> answer_list_2;
                    Node *disp_2;
                    disp_2 = this_row_child_2[j].get();
                    answer_list_2.push_back((disp_2));
                    disp_1 = this_row_child_1[i].get();
                    answer_list_1.push_back((disp_1));
                    while (true)
                    {
                        if (is_id_final(to_id(disp_1->matrix), source_f))
                        {
                            break;
                        }
                        answer_list_1.push_back((disp_1->parent));

                        disp_1 = disp_1->parent;
                    }
                    while (true)
                    {
                        if (is_id_final(to_id(disp_2->matrix), source_b))
                        {
                            break;
                        }
                        answer_list_2.push_back((disp_2->parent));

                        disp_2 = disp_2->parent;
                    }
                    std::reverse(std::begin(answer_list_1), std::end(answer_list_1));
                    answer_list_2.erase (answer_list_2.begin(),answer_list_2.begin()+1);
                    answer_list_1.insert(std::end(answer_list_1), std::begin(answer_list_2), std::end(answer_list_2)) ;
                   // std::reverse(std::begin(answer_list_2), std::end(answer_list_2));
                    //  std::cout << "hello" << std::endl;
                    for (size_t i{0}; i < answer_list_1.size(); i++)

                    {
                        std::time_t start = time(0);
                        while (difftime(std::time(0), start) <= 1)
                            ;
                        //   "2 - Custom source with default goal"
                        std::cout << "\033[94;1m" << i << ":"
                                  << "\033[0m" << std::endl;
                       // std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                        disp_matrix(answer_list_1[i]->matrix);
                      //  std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    }
                    // for (size_t i{0}; i < answer_list_2.size(); i++)

                    // {
                    //     std::time_t start = time(0);
                    //     while (difftime(std::time(0), start) <= 1)
                    //         ;
                    //     //   "2 - Custom source with default goal"
                    //     std::cout << "\033[94;1m" << i << ":"
                    //               << "\033[0m" << std::endl;
                    //     std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    //     disp_matrix(answer_list_2[i]->matrix);
                    //     std::cout << "\033[92;1m***********************\033[0m" << std::endl;
                    // }
                        
                    
                        return 0 ; 
                    }
                }
                
            }
            // for (size_t i = 0; i < this_row_child_1.size(); i++)
            // {
            //     std::cout << to_id(this_row_child_1[i]->matrix) << "-" << std::endl ;
            // }
            // std::cout << "8888888888888888888888888" << std::endl ;
            // for (size_t i = 0; i < this_row_child_2.size(); i++)
            // {
            //     std::cout << to_id(this_row_child_2[i]->matrix) << "-" << std::endl;
            // }
            
            
            this_row_child_1.clear();
            this_row_child_1 = this_row_child_next_1;
            this_row_child_2.clear();
            this_row_child_2 = this_row_child_next_2;

        }
    
     return 0 ; 
}

}



std::vector<std::shared_ptr<Node>> create_Node_child_b(Node &a, int I_C, int J_C, int gm[N][N])
{

    std::vector<std::shared_ptr<Node>> list_child;

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
                for (size_t i{0}; i < check_stop_b.size(); i++)
                {
                    if (id == check_stop_b[i])
                    {

                        check = true;
                    }
                }
                if (check == false)
                {

                    // Node *crow = new Node;
                    // crow = &a;
                    check_stop_b.push_back(id);
                    // Node New{Node(crowl_mat)};

                    // list_child.push_back(New);
                    // a.childs.push_back(New);
                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    // *New = wq;
                    list_child.push_back(New);
                    a.childs.push_back(New);
                    // crow = nullptr;
                }
            }
        }
    }
    //check_stop_Node.clear();
    return list_child;
    // }
}

std::vector<std::shared_ptr<Node>> create_Node_child_f(Node &a, int I_C, int J_C, int gm[N][N])
{

    std::vector<std::shared_ptr<Node>> list_child;

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
                for (size_t i{0}; i < check_stop_f.size(); i++)
                {
                    if (id == check_stop_f[i])
                    {

                        check = true;
                    }
                }
                if (check == false)
                {

                    // Node *crow = new Node;
                    // crow = &a;
                    check_stop_f.push_back(id);
                    // Node New{Node(crowl_mat)};

                    // list_child.push_back(New);
                    // a.childs.push_back(New);
                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    // *New = wq;
                    list_child.push_back(New);
                    a.childs.push_back(New);
                    // crow = nullptr;
                }
            }
        }
    }
    //check_stop_Node.clear();
    return list_child;
    // }
}