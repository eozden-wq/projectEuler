#include <iostream>

/*
Platform: Project Euler
Problem: 9
Problem Name: Special Pythagorean Triplet

Problem Statement:
A Pythagorean triplet is a set of three natural numbers a < b < c, for which
    a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
int main()
{
    // a + b + c = 1000 => c < 1000 => a + b < 1000
    for (int c = 1000; c > 0; c--)
    {
        for (int b = c / 2; b > 0; b--)
        {
            int a = 1000 - (c + b);
            if ((a * a) + (b * b) == (c * c))
                std::cout << a * b * c << std::endl;
        }
    }

    // answer - 31875000
}