#include "project.h"
#include <iostream>
#include "Node.h"
#include <cmath>
#include <vector>
#include <ctime>
#include <memory>
#include <iomanip>

typedef struct greaterSmaller Struct;

std::vector<int> check_stop_dfs;
std::vector<int> check_stop_bfs;
std::vector<int> check_stop_b;
std::vector<int> check_stop_f;
std::vector<int> disp_vec;
std::vector<int> bidirectional_f;
std::vector<int> bidirectional_b;
// function for solving bfs
int solve_bfs(Node &a, int gm[3][3], int m[3][3], int source, int depth)
{
    int func_depth;
    func_depth = 0;
    std::vector<std::shared_ptr<Node>> this_row_child = create_bfs_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    std::vector<std::shared_ptr<Node>> this_row_child_next;
    // first check for the first puzzle 
    if (is_final(m, gm) == true)
    {
        std::cout << std::endl;
        std::cout << "\033[36;1mHere is the answer :\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\033[94;1m" << 1 << ":"
                  << "\033[0m" << std::endl;
        std::cout << std::endl;
        disp_matrix(m);
        return 0;
    }
    else
    {
        while (true)
        {
            this_row_child_next.clear();
            // checking for answer in the childs of previous node's childs 
            for (size_t i{0}; i < this_row_child.size(); i++)
            {

                if (is_final(this_row_child[i]->matrix, gm) == true)
                {

                    std::cout << std::endl;
                    std::cout << "\033[36;1mHere is the answer :\033[0m" << std::endl;
                    std::cout << std::endl;
                    disp_matrix(this_row_child[i]->matrix);

                    std::vector<Node *> answer_list;
                    Node *disp;

                    disp = this_row_child[i].get();
                    answer_list.push_back((disp));
                    // after finding the answer wants to show the amswer step by step 
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
                    // showing answer step by step 
                    for (size_t i{0}; i < answer_list.size(); i++)

                    {
                        std::time_t start = time(0);
                        while (difftime(std::time(0), start) <= 1)
                            ;
                        std::cout << "\033[94;1m" << i << ":"
                                  << "\033[0m" << std::endl;
                        std::cout << std::endl;
                        disp_matrix(answer_list[i]->matrix);
                    }

                    return 0;
                }
                else
                {
                    // creating next row's child of puzzle 
                    std::vector<std::shared_ptr<Node>> this_row_child_next_crowler = create_bfs_child(*this_row_child[i], find_zero_location(*this_row_child[i]).x, find_zero_location(*this_row_child[i]).y, gm);

                    for (size_t i{0}; i < this_row_child_next_crowler.size(); i++)
                    {
                        this_row_child_next.push_back(this_row_child_next_crowler[i]);
                    }
                }
            }
            func_depth++;
            if (func_depth >= depth)
            {
                std::cout << std::endl;
                std::cout << "\033[1;31mThere is no answer\033[0m" << std::endl;
                std::cout << std::endl;
                return 0;
            }

            this_row_child.clear();
            //setting next row's child to this_row_child for next interation in while 
            this_row_child = this_row_child_next;
        }
    }
}
// creating childs of bfs 
std::vector<std::shared_ptr<Node>> create_bfs_child(Node &a, int I_C, int J_C, int gm[3][3])
{

    std::vector<std::shared_ptr<Node>> list_child;

    for (int i{0}; i < 3; i++)
    {

        for (int j{0}; j < 3; j++)
        {

            if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
            {

                int crowl_mat[3][3];
                set_equal(crowl_mat, a.matrix);
                std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
                int id = to_id(crowl_mat);
                bool check = false;

                if (std::find(check_stop_bfs.begin(), check_stop_bfs.end(), id) != check_stop_bfs.end())
                {
                    check = true;
                }
                if (check == false)
                {

                    check_stop_bfs.push_back(id);
                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    list_child.push_back(New);
                    a.childs.push_back(New);
                }
            }
        }
    }

    return list_child;
}

int finished_answer_dfs = 0;
int layer_dfs = 0;
// finction for solving dfs
int solve_dfs(Node &a, int gm, int m[3][3], int source, int depth)
{
    if (to_id(a.matrix) == source)
    {
        check_stop_dfs.push_back(to_id(m));
    }
    std::vector<std::shared_ptr<Node>> this_row_child = create_dfs_child(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    if (is_id_final(to_id(m), gm) == true)
    {

        std::cout << std::endl;
        std::cout << "\033[36;1mHere is the answer :\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\033[94;1m" << 1 << ":"
                  << "\033[0m" << std::endl;
        std::cout << std::endl;
        disp_matrix(m);
        return 0;
    }

    else
    {

        for (size_t i{0}; i < this_row_child.size(); i++)
        {

            if (finished_answer_dfs == 1)
            {
                return 0;
            }
            if (is_id_final(to_id(this_row_child[i]->matrix), gm) == true)
            {
                finished_answer_dfs = 1;
                std::cout << std::endl;
                std::cout << "\033[36;1mHere is the answer :\033[0m" << std::endl;
                std::cout << std::endl;

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
                for (size_t i{0}; i < answer_list.size(); i++)
                {

                    std::time_t start = time(0);
                    while (difftime(std::time(0), start) <= 1)
                        ;

                    std::cout << "\033[94;1m" << i << ":"
                              << "\033[0m" << std::endl
                              << std::endl;

                    disp_matrix(answer_list[i]->matrix);
                }

                return 0;
            }
            else
            {

                if (layer_dfs < depth - 1)
                {

                    layer_dfs++;
                    solve_dfs(*this_row_child[i], gm, this_row_child[i]->matrix, source, depth);
                }
            }
        }

        check_stop_dfs.resize(check_stop_dfs.size() - this_row_child.size());

        layer_dfs--;
    }
    return 0;
}
// create dfs child
std::vector<std::shared_ptr<Node>> create_dfs_child(Node &a, int I_C, int J_C, int gm)
{

    std::vector<std::shared_ptr<Node>> list_child;

    for (int i{0}; i < 3; i++)
    {

        for (int j{0}; j < 3; j++)
        {

            if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
            {

                int crowl_mat[3][3];
                set_equal(crowl_mat, a.matrix);
                std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
                int id = to_id(crowl_mat);
                bool check = false;

                if (std::find(check_stop_dfs.begin(), check_stop_dfs.end(), id) != check_stop_dfs.end())
                {
                    check = true;
                }
                if (check == false)
                {

                    check_stop_dfs.push_back(id);
                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    list_child.push_back(New);
                    a.childs.push_back(New);
                }
            }
        }
    }

    return list_child;
}
// function for solving bidirectal
int solve_bidirectional(Node &a, Node &b, int gm[3][3], int m[3][3], int source_f, int source_b, int depth)
{

    bool b_ans = false;
    int bi_depth = 0;
    std::vector<std::shared_ptr<Node>> this_row_child_1 = create_bfs_child_b(a, find_zero_location(a).x, find_zero_location(a).y, gm);
    std::vector<std::shared_ptr<Node>> this_row_child_next_1;
    std::vector<std::shared_ptr<Node>> this_row_child_2 = create_bfs_child_f(b, find_zero_location(b).x, find_zero_location(b).y, m);
    std::vector<std::shared_ptr<Node>> this_row_child_next_2;
    if (is_final(a.matrix, b.matrix) == true)
    {

        std::cout << std::endl;
        std::cout << "\033[36;1mHere is the answer :\033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\033[94;1m" << 1 << ":"
                  << "\033[0m" << std::endl;
        std::cout << std::endl;
        disp_matrix(m);
        return 0;
    }
    else
    {
        while (true)
        {

            if (bi_depth >= depth)
            {
                if (b_ans == false)
                {
                    std::cout << std::endl;
                    std::cout << "\033[1;31mThere is no answer\033[0m" << std::endl;
                    std::cout << std::endl;
                    return 0;
                }
            }
            for (size_t i{0}; i < this_row_child_1.size(); i++)
            {

                std::vector<std::shared_ptr<Node>> this_row_child_next_crowler_1 = create_bfs_child_b(*this_row_child_1[i], find_zero_location(*this_row_child_1[i]).x, find_zero_location(*this_row_child_1[i]).y, gm);

                for (size_t i{0}; i < this_row_child_next_crowler_1.size(); i++)
                {
                    this_row_child_next_1.push_back(this_row_child_next_crowler_1[i]);
                }
            }
            for (size_t i{0}; i < this_row_child_2.size(); i++)
            {

                std::vector<std::shared_ptr<Node>> this_row_child_next_crowler_2 = create_bfs_child_f(*this_row_child_2[i], find_zero_location(*this_row_child_2[i]).x, find_zero_location(*this_row_child_2[i]).y, gm);

                for (size_t i{0}; i < this_row_child_next_crowler_2.size(); i++)
                {
                    this_row_child_next_2.push_back(this_row_child_next_crowler_2[i]);
                }
            }

            for (size_t i = 0; i < this_row_child_1.size(); i++)
            {
                for (size_t j = 0; j < this_row_child_2.size(); j++)
                {
                    if (is_id_final(to_id(this_row_child_2[j]->matrix), to_id(this_row_child_1[i]->matrix)) == true)
                    {

                        b_ans = true;
                        std::cout << std::endl;
                        std::cout << "\033[35;1mThey reach together at this matrix :\033[0m" << std::endl;
                        std::cout << std::endl;
                        disp_matrix(this_row_child_2[j]->matrix);

                        std::cout << std::endl;
                        std::cout << "\033[36;1mHere is the answer :\033[0m" << std::endl;
                        std::cout << std::endl;
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
                        answer_list_2.erase(answer_list_2.begin(), answer_list_2.begin() + 1);
                        answer_list_1.insert(std::end(answer_list_1), std::begin(answer_list_2), std::end(answer_list_2));

                        for (size_t i{0}; i < answer_list_1.size(); i++)

                        {
                            std::time_t start = time(0);
                            while (difftime(std::time(0), start) <= 1)
                                ;

                            std::cout << "\033[94;1m" << i << ":"
                                      << "\033[0m" << std::endl
                                      << std::endl;

                            disp_matrix(answer_list_1[i]->matrix);
                        }

                        return 0;
                    }
                }
            }

            this_row_child_1.clear();
            this_row_child_1 = this_row_child_next_1;
            this_row_child_2.clear();
            this_row_child_2 = this_row_child_next_2;

            bi_depth++;
        }

        return 0;
    }
}
// creating forward child of bfs
std::vector<std::shared_ptr<Node>> create_bfs_child_b(Node &a, int I_C, int J_C, int gm[3][3])
{

    std::vector<std::shared_ptr<Node>> list_child;

    for (int i{0}; i < 3; i++)
    {

        for (int j{0}; j < 3; j++)
        {
           // checking for that is a puzzle child of a.matrix puzzle or not  
            if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
            {

                int crowl_mat[3][3];
                set_equal(crowl_mat, a.matrix);
                std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
                int id = to_id(crowl_mat);
                bool check = false;
                
                //  checking for existance in the list of created puzzle 
                if (std::find(check_stop_b.begin(), check_stop_b.end(), id) != check_stop_b.end())
                {
                    check = true;
                }
                if (check == false)
                {

                    check_stop_b.push_back(id);

                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    list_child.push_back(New);
                    a.childs.push_back(New);
                }
            }
        }
    }

    return list_child;
}
//creating backward child of bfs
std::vector<std::shared_ptr<Node>> create_bfs_child_f(Node &a, int I_C, int J_C, int gm[3][3])
{

    std::vector<std::shared_ptr<Node>> list_child;

    for (int i{0}; i < 3; i++)
    {

        for (int j{0}; j < 3; j++)
        {
            // checking for that is a puzzle child of a.matrix puzzle or not  
            if (std::abs(i - I_C) + std::abs(j - J_C) == 1)
            {

                int crowl_mat[3][3];
                set_equal(crowl_mat, a.matrix);
                std::swap(crowl_mat[i][j], crowl_mat[I_C][J_C]);
                int id = to_id(crowl_mat);
                bool check = false;
                //  checking for existance in the list of created puzzle 
                if (std::find(check_stop_bfs.begin(), check_stop_bfs.end(), id) != check_stop_bfs.end())
                {
                    check = true;
                }
                if (check == false)
                {

                    check_stop_f.push_back(id);
                    std::shared_ptr<Node> New(new Node(&a, crowl_mat));
                    list_child.push_back(New);
                    a.childs.push_back(New);
                }
            }
        }
    }

    return list_child;
}
// chedcking for equality of 2 puzzle 
bool is_final(int m[3][3], int gm[3][3])
{
    bool check = true;
    for (size_t i{0}; i < 3; i++)
    {
        for (size_t j{0}; j < 3; j++)
        {

            if (m[i][j] != gm[i][j])
            {
                check = false;
            }
        }
    }
    return check;
}
// fuinding the location of 0 of the puzzle 
Struct find_zero_location(Node &a)
{

    Struct s;
    for (size_t i{0}; i < 3; i++)
    {
        for (size_t j{0}; j < 3; j++)
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
// setting 1 matrix equal to another 
void set_equal(int wanted_mat[3][3], int from_mat[3][3])
{

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

// display matrix in a beautifull way 
void disp_matrix(int matrix[3][3])
{

    for (size_t i{0}; i < 3; i++)
    {
        for (size_t j{0}; j < 3; j++)
        {
            if (j == 0)
            {
                if (matrix[i][j] == 0)
                {
                    std::cout << "\033[96;1;101m"
                              << "  " << (matrix[i][j]) << "  "
                              << "\033[0m"
                              << " ";
                }

                else
                {
                    std::cout << "\033[96;1;103m"
                              << "  " << (matrix[i][j]) << "  "
                              << "\033[0m"
                              << " ";
                }
            }

            else
            {
                if (matrix[i][j] == 0)
                {
                    std::cout << "\033[96;1;101m"
                              << "  " << matrix[i][j] << "  "
                              << "\033[0m"
                              << " ";
                }
                else
                {

                    std::cout << "\033[96;1;103m"
                              << "  " << matrix[i][j] << "  "
                              << "\033[0m"
                              << " ";
                }
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
// coverting a puzzle to a 9 digit integer for better performance 
int to_id(int matrix[3][3])
{

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
    int idd = (std::pow(10, 8)) * id[0] + (std::pow(10, 7)) * id[1] + (std::pow(10, 6)) * id[2] +
     (std::pow(10, 5)) * id[3] + (std::pow(10, 4)) * id[4] + (std::pow(10, 3)) * id[5] 
    + (std::pow(10, 2)) * id[6] + (std::pow(10, 1)) * id[7] + (std::pow(10, 0)) * id[8];
    return idd;
}
// checking 2 puzzle by their id 
bool is_id_final(int a, int b)
{
    return a == b;
}
// checking ssolvability of 2 puzzle 
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i + 1; j < 9; j++)
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}
bool isSolvable(int puzzle[3][3])
{

    int invCount = getInvCount((int *)puzzle);

    return (invCount % 2 == 0);
}
