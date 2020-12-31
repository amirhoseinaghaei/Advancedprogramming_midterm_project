#include <iostream>
#include <memory>
#include <vector>
#include "project.h"
#include <ctime>
#include <iomanip>
#include "Node.h"

int state;
int ans;
int condition = 0;

int main()
{
    srand(time(0));

    std::cout << std::endl
              << std::endl;
    std::cout << "\033[1;95;105m" << std::setw(61) << std::left << "                                  555                                                       \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;31;107m" << std::setw(61) << std::left << "                                     Hello there                                            \033[0m " << std::endl;
    std::cout << "\033[1;31;107m" << std::setw(61) << std::left << "                  This is 8-puzzle solver program by Amir Hossein Aghaei                    \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;92;107m" << std::setw(61) << std::left << " Please choose one of this state                                                            \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(61) << std::left << "1 - Custom source with custom goal puzzle                                                   \033[0m " << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(60) << std::left << "2 - Custom source with default goal puzzle                                                  \033[0m" << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(61) << std::left << "3 - Random source with custom goal puzzle                                                   \033[0m " << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(60) << std::left << "4 - Random source with default goal puzzle                                                  \033[0m" << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;95;105m" << std::setw(61) << std::left << "                              555                                                           \033[0m " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\033[1;95m=> :  \033[0m ";
    std::cin >> state;
    std::cout << std::endl;
    int matrix[3][3];
    int goal_matrix[3][3];

    if (state == 1)
    {

        int int_matrix;
        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter your first puzzle: \033[0m" << std::endl;
        std::cout << std::endl;

        std::cout << "\033[1;95m-------------------------------------------\033[0m " << std::endl;

        std::cout << "\033[1;94mFor example like this :\033[0m " << std::endl;
        std::cout << std::endl;
        int example_mat[3][3];
        example_mat[0][0] = 1;
        example_mat[0][1] = 2;
        example_mat[0][2] = 3;
        example_mat[1][0] = 5;
        example_mat[1][1] = 4;
        example_mat[1][2] = 7;
        example_mat[2][0] = 6;
        example_mat[2][1] = 8;
        example_mat[2][2] = 0;
        disp_matrix(example_mat);
        std::cout << "\033[1;94m=> : 123547680\033[0m " << std::endl;
        std::cout << "\033[1;95m-------------------------------------------\033[0m " << std::endl;
        std::cout << std::endl;
        while (condition == 0)
        {
            std::cout << "\033[1;95m=> :  \033[0m ";
            std::cin >> int_matrix;

            matrix[0][0] = int_matrix / 100000000 % 10;
            matrix[0][1] = int_matrix / 10000000 % 10;
            matrix[0][2] = int_matrix / 1000000 % 10;
            matrix[1][0] = int_matrix / 100000 % 10;
            matrix[1][1] = int_matrix / 10000 % 10;
            matrix[1][2] = int_matrix / 1000 % 10;
            matrix[2][0] = int_matrix / 100 % 10;
            matrix[2][1] = int_matrix / 10 % 10;
            matrix[2][2] = int_matrix % 10;

            if (isSolvable(matrix))
            {
                std::cout << std::endl;
                std::cout << "\033[92;1mSolvable \033[0m" << std::endl;
                std::cout << std::endl;
                condition = 1;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "\033[91;1mNot solvable \033[0m" << std::endl;
                std::cout << std::endl;

                std::cout << std::endl;
                std::cout << "\033[33;1mPlease enter your valid first puzzle: \033[0m" << std::endl;
                std::cout << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter goal puzzle: \033[0m" << std::endl;
        std::cout << std::endl;
        int int_goal_matrix;
        std::cout << "\033[1;95m=> :  \033[0m ";
        std::cin >> int_goal_matrix;

        goal_matrix[0][0] = int_goal_matrix / 100000000 % 10;
        goal_matrix[0][1] = int_goal_matrix / 10000000 % 10;
        goal_matrix[0][2] = int_goal_matrix / 1000000 % 10;
        goal_matrix[1][0] = int_goal_matrix / 100000 % 10;
        goal_matrix[1][1] = int_goal_matrix / 10000 % 10;
        goal_matrix[1][2] = int_goal_matrix / 1000 % 10;
        goal_matrix[2][0] = int_goal_matrix / 100 % 10;
        goal_matrix[2][1] = int_goal_matrix / 10 % 10;
        goal_matrix[2][2] = int_goal_matrix % 10;
    }

    if (state == 2)
    {
        int int_matrix;
        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter your first puzzle: \033[0m" << std::endl;
        std::cout << std::endl;

        std::cout << "\033[1;95m-------------------------------------------\033[0m " << std::endl;

        std::cout << "\033[1;94mFor example like this :\033[0m " << std::endl;
        std::cout << std::endl;
        int example_mat[3][3];
        example_mat[0][0] = 1;
        example_mat[0][1] = 2;
        example_mat[0][2] = 3;
        example_mat[1][0] = 5;
        example_mat[1][1] = 4;
        example_mat[1][2] = 7;
        example_mat[2][0] = 6;
        example_mat[2][1] = 8;
        example_mat[2][2] = 0;
        disp_matrix(example_mat);
        std::cout << "\033[1;94m=> : 123547680\033[0m " << std::endl;
        std::cout << "\033[1;95m-------------------------------------------\033[0m " << std::endl;
        std::cout << std::endl;
        while (condition == 0)
        {
            std::cout << "\033[1;95m=> :  \033[0m ";
            std::cin >> int_matrix;
            matrix[0][0] = int_matrix / 100000000 % 10;
            matrix[0][1] = int_matrix / 10000000 % 10;
            matrix[0][2] = int_matrix / 1000000 % 10;
            matrix[1][0] = int_matrix / 100000 % 10;
            matrix[1][1] = int_matrix / 10000 % 10;
            matrix[1][2] = int_matrix / 1000 % 10;
            matrix[2][0] = int_matrix / 100 % 10;
            matrix[2][1] = int_matrix / 10 % 10;
            matrix[2][2] = int_matrix % 10;

            if (isSolvable(matrix))
            {
                std::cout << std::endl;
                std::cout << "\033[92;1mSolvable \033[0m" << std::endl;
                std::cout << std::endl;
                condition = 1;
            }
            else
            {
                std::cout << std::endl;
                std::cout << "\033[91;1mNot solvable \033[0m" << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "\033[33;1mPlease enter your valid first puzzle: \033[0m" << std::endl;
                std::cout << std::endl;
            }
        }

        goal_matrix[0][0] = 1;
        goal_matrix[0][1] = 2;
        goal_matrix[0][2] = 3;
        goal_matrix[1][0] = 4;
        goal_matrix[1][1] = 5;
        goal_matrix[1][2] = 6;
        goal_matrix[2][0] = 7;
        goal_matrix[2][1] = 8;
        goal_matrix[2][2] = 0;
    }
    if (state == 3)
    {
        srand(time(0));
        int r;
        std::vector<int> rand_list;

        bool rand_check = 0;
        for (size_t i{0}; i < 3; i++)
        {
            for (size_t j{0}; j < 3; j++)
            {

                r = (rand() % 9);
                while (rand_check == 0)
                {
                    if (std::find(rand_list.begin(), rand_list.end(), r) == rand_list.end())
                    {

                        matrix[i][j] = r;
                        rand_list.push_back(r);
                        rand_check = 1;
                    }
                    else
                    {
                        r = (rand() % 9);
                    }
                }

                rand_check = 0;
            }
        }

        std::cout << std::endl;
        std::cout << "\033[36;1mThis is your primary matrix: \033[0m" << std::endl;
        std::cout << std::endl;
        disp_matrix(matrix);

        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter goal puzzle: \033[0m" << std::endl;
        std::cout << std::endl;
        std::cout << "\033[1;95m-------------------------------------------\033[0m " << std::endl;

        std::cout << "\033[1;94mFor example like this :\033[0m " << std::endl;
        std::cout << std::endl;
        int example_mat[3][3];
        example_mat[0][0] = 1;
        example_mat[0][1] = 2;
        example_mat[0][2] = 3;
        example_mat[1][0] = 5;
        example_mat[1][1] = 4;
        example_mat[1][2] = 7;
        example_mat[2][0] = 6;
        example_mat[2][1] = 8;
        example_mat[2][2] = 0;
        disp_matrix(example_mat);
        std::cout << "\033[1;94m=> : 123547680\033[0m " << std::endl;
        std::cout << "\033[1;95m-------------------------------------------\033[0m " << std::endl;
        std::cout << std::endl;

        int int_goal_matrix;
        std::cout << "\033[1;95m=> :  \033[0m ";
        std::cin >> int_goal_matrix;

        goal_matrix[0][0] = int_goal_matrix / 100000000 % 10;
        goal_matrix[0][1] = int_goal_matrix / 10000000 % 10;
        goal_matrix[0][2] = int_goal_matrix / 1000000 % 10;
        goal_matrix[1][0] = int_goal_matrix / 100000 % 10;
        goal_matrix[1][1] = int_goal_matrix / 10000 % 10;
        goal_matrix[1][2] = int_goal_matrix / 1000 % 10;
        goal_matrix[2][0] = int_goal_matrix / 100 % 10;
        goal_matrix[2][1] = int_goal_matrix / 10 % 10;
        goal_matrix[2][2] = int_goal_matrix % 10;
    }
    if (state == 4)
    {

        srand(time(0));
        while (condition == 0)
        {
            int r;
            std::vector<int> rand_list;

            bool rand_check = 0;
            for (size_t i{0}; i < 3; i++)
            {
                for (size_t j{0}; j < 3; j++)
                {

                    r = (rand() % 9);
                    while (rand_check == 0)
                    {
                        if (std::find(rand_list.begin(), rand_list.end(), r) == rand_list.end())
                        {

                            matrix[i][j] = r;
                            rand_list.push_back(r);
                            rand_check = 1;
                        }
                        else
                        {
                            r = (rand() % 9);
                        }
                    }

                    rand_check = 0;
                }
            }
            std::cout << std::endl;
            std::cout << "\033[36;1mThis is your primary matrix: \033[0m" << std::endl;
            std::cout << std::endl;
            disp_matrix(matrix);
            if (isSolvable(matrix))
            {
                std::cout << std::endl;
                std::cout << "\033[92;1mSolvable \033[0m" << std::endl;
                std::cout << std::endl;
                condition = 1;
            }
        }
        goal_matrix[0][0] = 1;
        goal_matrix[0][1] = 2;
        goal_matrix[0][2] = 3;
        goal_matrix[1][0] = 4;
        goal_matrix[1][1] = 5;
        goal_matrix[1][2] = 6;
        goal_matrix[2][0] = 7;
        goal_matrix[2][1] = 8;
        goal_matrix[2][2] = 0;
    }

    Node a{matrix};
    Node b{goal_matrix};
    std::cout << std::endl;
    std::cout << "\033[1;95;105m" << std::setw(61) << std::left << "                                  555                                                       \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;92;107m" << std::setw(61) << std::left << "Which way do you prefer?                                                                    \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(61) << std::left << "1-BFS                                                                                       \033[0m " << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(61) << std::left << "2-DFS                                                                                       \033[0m " << std::endl;
    std::cout << "\033[1;34;107m" << std::setw(61) << std::left << "3-BIDIRECTIONAL                                                                             \033[0m " << std::endl;
    std::cout << "\033[0;30;107m" << std::setw(61) << std::left << "                                                                                            \033[0m " << std::endl;
    std::cout << "\033[1;95;105m" << std::setw(61) << std::left << "                                  555                                                       \033[0m " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\033[1;95m=> :  \033[0m ";
    std::cin >> ans;
    std::cout << std::endl;
    if (ans == 1)
    {
        int depth;
        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter depth of the algorithm: \033[0m" << std::endl;
        std::cout << std::endl;
        std::cin >> depth;
        solve_bfs(a, goal_matrix, matrix, to_id(matrix), depth);
    }
    if (ans == 2)
    {
        int depth;
        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter depth of the algorithm: \033[0m" << std::endl;
        std::cout << std::endl;
        std::cin >> depth;
        solve_dfs(a, to_id(goal_matrix), matrix, to_id(matrix), depth);
    }
    if (ans == 3)

    {
        int depth;
        std::cout << std::endl;
        std::cout << "\033[33;1mPlease enter depth of both side togehter of the algorithm: \033[0m" << std::endl;
        std::cout << std::endl;
        std::cin >> depth;
        solve_bidirectional(a, b, goal_matrix, matrix, to_id(matrix), to_id(goal_matrix), depth);
    }

    return 0;
}
