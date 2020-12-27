#include <iostream>
#include <memory>
#include <vector>
#include "project.cpp"
#include <ctime>
#include <iomanip>

// #include "dfs.h"
// #include "dfs.cpp"
#include "Node.h"
#define N 3
// #include "project.h"
int state;
int ans;
int condition = 0;
int main()
{
    srand(time(0));

    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "Hello there this is 8-puzzle solver program                                                 \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "                                                                                            \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "                                                                                            \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "                                                                                            \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "                                                                                            \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "Please choose one of this state                                                             \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "                                                                                            \033[0m "  << std::endl ;
    std::cout << "\033[0;31;107m"  << std::setw(61) << std::left << "1 - Custom source with custom goal puzzle                                                   \033[0m " << std::endl;
    std::cout << "\033[0;32;107m"  << std::setw(60) << std::left << "2 - Custom source with default goal puzzle                                                  \033[0m" << std::endl;
    std::cout << "\033[0;34;107m"  << std::setw(61) << std::left << "3 - Random source with custom goal puzzle                                                   \033[0m " << std::endl;
    std::cout << "\033[0;35;107m"  << std::setw(60) << std::left << "4 - Random source with default goal puzzle                                                  \033[0m" << std::endl;

    std::cin >> state;
    int matrix[N][N];
    int goal_matrix[N][N];

    if (state == 1)
    {

        int int_matrix;
        std::cout << "Please enter your first puzzle" << std::endl;
        while (condition == 0)
        {
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
                std::cout << "Solvable";
                condition = 1;
            }
            else
            {
                std::cout << "Not Solvable" << std::endl;
                std::cout << "Please enter your valid first puzzle" << std::endl;
            }
        }

        std::cout << "Please enter goal puzzle" << std::endl;
        int int_goal_matrix;
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
        std::cout << "Please enter your first puzzle" << std::endl;
        while (condition == 0)
        {
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
                std::cout << "Solvable";
                condition = 1;
            }
            else
            {
                std::cout << "Not Solvable" << std::endl;
                std::cout << "Please enter your valid first puzzle" << std::endl;
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
        while (condition == 0)
        {
            int r;
            std::vector<int> rand_list;

            bool rand_check = 0;
            for (size_t i{0}; i < N; i++)
            {
                for (size_t j{0}; j < N; j++)
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
                            std::cout << r << std::endl;
                        }
                    }

                    rand_check = 0;
                }
            }
            disp_matrix(matrix);
            if (isSolvable(matrix))
            {
                std::cout << "Solvable" << std::endl;
                condition = 1;
            }
            else
            {
                std::cout << "Not Solvable" << std::endl;
            }
        }

        std::cout << "Please enter goal puzzle" << std::endl;
        int int_goal_matrix;
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
            for (size_t i{0}; i < N; i++)
            {
                for (size_t j{0}; j < N; j++)
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
                            std::cout << r << std::endl;
                        }
                    }

                    rand_check = 0;
                }
            }
            disp_matrix(matrix);
            if (isSolvable(matrix))
            {
                std::cout << "Solvable" << std::endl;
                condition = 1;
            }
            else
            {
                std::cout << "Not Solvable" << std::endl;
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
    check_stop_Node.push_back(to_id(matrix));
    std::cout << "Which way do you prefer?" << std::endl;
    std::cout << "1-Node" << std::endl;
    std::cout << "2-DFS" << std::endl;
    std::cout << "2-BIO" << std::endl;
    std::cin >> ans;

    if (ans == 1)
    {
        int depth;
        std::cout << "Please enter depth of the algorithm" << std::endl;
        std::cin >> depth;
        solve_Node(a, goal_matrix, matrix, to_id(matrix), depth);
    }
    if (ans == 2)

    {
        solve_dfs(a, to_id(goal_matrix), matrix, to_id(matrix));
    }
     if (ans == 3)

    {
        solve_biodirectal(a , b, goal_matrix , matrix, to_id(matrix) , to_id(goal_matrix)) ;
    }
    // for (size_t i = 0; i < check_stop_Node.size(); i++)
    // {
    //     std::cout <<i <<check_stop_Node[i] << std::endl ;
    // }

    return 0;
}
