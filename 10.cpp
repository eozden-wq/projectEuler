#include <iostream>
#include <vector>

/*
Platform: Project Euler
Problem: 10
Problem Name: Summation of Primes

Problem Statement:
The sum of primes below 10 is 2 + 3 + 5 + 7 = 17

Find the sum of all the primes below two million
*/
int main(int argc, char **argv)
{
    const int TARGET = 2000000;
    std::vector<bool> sieve(TARGET, true);

    for (int p = 2; p * p < TARGET; p++)
    {
        if (sieve[p])
            for (int i = p * p; i < TARGET; i += p)
                sieve[i] = false;
    }

    unsigned long long int res = 0;
    for (int i = 2; i < TARGET; i++)
        if (sieve[i])
        {

            res += i;
        }

    std::cout << res << std::endl;
    // answer - 142913828922
}