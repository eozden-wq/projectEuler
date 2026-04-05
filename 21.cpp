#include <iostream>
#include <cstdint>

/*
Platform: Project Euler
Problem: 21
Problem Name: Amicable Numbers

Problem Statement:
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called
amicable numbers.
*/
int d(int n)
{
    int res = 0;
    for (int i = 1; i <= n / 2; i++)
        if (!(n % i))
            res += i;

    return res;
}

int main(int argc, char **argv)
{
    uint64_t res = 0;

    for (int i = 1; i < 10000; i++)
        if (i == d(d(i)) && i != d(i))
            res += i;

    std::cout << res;
    // answer - 31626
}