#include <iostream>
#include <vector>

int main()
{
    std::vector<bool> sieve(500000, true);
    std::vector<int> primes = {};

    for (int i = 2; i * i < 500000; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j < 500000; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i < 500000; i++)
        if (sieve[i])
            primes.push_back(i);

    std::cout << primes.size() << std::endl;
    std::cout << primes[10000];
}