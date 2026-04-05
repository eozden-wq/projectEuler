#include <iostream>
#include <cstdint>

/*
Platform: Project Euler
Problem: 14
Problem Name: Longest Collatz Sequence

Problem Statement:
The following iterative sequence is defined for the set of positive integers:
$n \to n/2$ ($n$ is even)
$n \to 3n + 1$ ($n$ is odd)
Using the rule above and starting with $13$, we generate the following sequence:
$$13 \to 40 \to 20 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1.$$
It can be seen that this sequence (starting at $13$ and finishing at $1$) contains $10$ terms.
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers
finish at $1$.
Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one million.
*/
uint64_t collatz(uint32_t n)
{
    uint64_t chain_length = 1;

    while (n != 1)
    {
        if (!(n % 2))
        {
            while (!(n % 2))
            {
                n /= 2;
                chain_length++;
            }
        }
        else
        {
            n = (3 * n) + 1;
            chain_length++;
        }
    }

    return chain_length;
}

int main()
{
    int result = 0;
    uint64_t result_chain_length = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        uint64_t i_steps = collatz(i);
        if (i_steps > result_chain_length)
        {
            result = i;
            result_chain_length = i_steps;
        }
    }

    std::cout << result << std::endl;
    // answer - 837799
}