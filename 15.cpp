#include <iostream>
#include <vector>
#include <cstdint>

/*
Platform: Project Euler
Problem: 15
Problem Name: Lattice Paths

Problem Statement:
Starting in the top left corner of a 2x2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner. How
many such routes are there through a 20x20 grid.
*/
int main(int argc, char **argv)
{
    int n = 20;
    std::vector<std::vector<uint64_t>> dp(n + 1, std::vector<uint64_t>(n + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    std::cout << dp[n][n] << std::endl;
    // answer - 137846528820
}