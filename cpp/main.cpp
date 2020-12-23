#include <iostream>
#include <memory>
#include <vector>
#include "project.cpp"
#include <ctime>
// #include "dfs.h"
// #include "dfs.cpp"
#include "bfs.h"
#define N 3
// #include "project.h"
int state;
int main()
{
    srand(time(0));
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

    std::cout << "1 - Custom source and goal puzzle" << std::endl;
    std::cout << "2 - Custom source with default goal" << std::endl;
    std::cout << "3 - Random source with custom goal puzzle" << std::endl;
    std::cout << "4 - Custom source with random goal puzzle" << std::endl;
    std::cout << "5 - Random source and goal puzzle" << std::endl;
    std::cin >> state;
    int matrix[N][N];
    int goal_matrix[N][N];

    if (state == 1)
    {
        std::cout << "Please enter your first puzzle" << std::endl;
        for (size_t i{0}; i < N; i++)
        {
            for (size_t j{0}; j < N; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
        if (isSolvable(matrix))
        {
            std::cout << "Solvable";
        }
        else
        {
            std::cout << "Not Solvable" << std::endl;
            return 0;
        }

        std::cout << "Please enter goal puzzle" << std::endl;
        for (size_t i{0}; i < N; i++)
        {
            for (size_t j{0}; j < N; j++)
            {
                std::cin >> goal_matrix[i][j];
            }
        }
    }

    if (state == 2)
    {
        std::cout << "Please enter your first puzzle" << std::endl;
        for (size_t i{0}; i < N; i++)
        {
            for (size_t j{0}; j < N; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
        if (isSolvable(matrix))
        {
            std::cout << "Solvable";
        }
        else
        {
            std::cout << "Not Solvable" << std::endl;
            return 0;
        }

        std::cout << "Please enter goal puzzle" << std::endl;
        // for (size_t i{0}; i < N; i++)
        // {
        //     for (size_t j{0}; j < N; j++)
        //     {
        //        goal_matrix[i][j];
        //     }
        // }
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
        int r;
        std::vector<int> rand_list;
        srand(time(0));
        bool rand_check = 0;
        std::cout << "Please enter your first puzzle" << std::endl;
        for (size_t i{0}; i < N; i++)
        {
            for (size_t j{0}; j < N; j++)
            {

                r = (rand() % 9);
                // if (i == 0 && j == 0)
                // {
                //     matrix[i][j] = r;
                //     // matrix[i][j] = r;
                //     rand_list.push_back(r);
                // }
                while (rand_check == 0)
                {
                    if (std::find(rand_list.begin(), rand_list.end(), r) == rand_list.end())
                    {

                        matrix[i][j] = r;
                        // matrix[i][j] = r;
                        rand_list.push_back(r);
                        rand_check = 1;
                        //      break;
                    }
                    else
                    {
                        r = (rand() % 9);
                        std::cout << r << std::endl;
                    }
                }
                // if (i == 0 && j == 0)
                // {
                //     matrix[i][j] = r;
                //     // matrix[i][j] = r;
                //     rand_list.push_back(r);
                // }
                rand_check = 0;

                // rand_check = true ;
                // for (i = 0; i < 3; ++i)
                // {
                //     for (j = 0; j < 3; ++j)
                //     {

                //     }
                // }
            }
        }
        disp_matrix(matrix);
        if (isSolvable(matrix))
        {
            std::cout << "Solvable" << std::endl;
        }
        else
        {
            std::cout << "Not Solvable" << std::endl;
            return 0;
        }

        std::cout << "" << std::endl ;
        std::cout << "\e[1;34mPlease enter goal puzzle" << std::endl;
        for (size_t i{0}; i < N; i++)
        {
            for (size_t j{0}; j < N; j++)
            {
                std::cin >> goal_matrix[i][j];
            }
        }
        // goal_matrix[0][0] = 1;
        // goal_matrix[0][1] = 2;
        // goal_matrix[0][2] = 3;
        // goal_matrix[1][0] = 4;
        // goal_matrix[1][1] = 5;
        // goal_matrix[1][2] = 6;
        // goal_matrix[2][0] = 7;
        // goal_matrix[2][1] = 8;
        // goal_matrix[2][2] = 0;
    }
    bfs a{matrix};
    //check_stop_bfs.push_back(a);
    // disp_matrix(matrix);
    // disp_matrix(goal_matrix);
    check_stop_bfs.push_back(to_id(matrix));
    //solve_dfs(a, to_id(goal_matrix), matrix, to_id(matrix));
    solve_bfs(a, goal_matrix, matrix) ;
    // std::vector<int> a  ;
    // int d = 5 ;
    // a.push_back(d) ;
    // d = 7 ;
    // a.push_back(d);
    // std::cout << a[0] << a[1] << std::endl ;
    return 0;
}