#include <iostream>
#include <vector>
#include <cstdint>

/*
Platform: Project Euler
Problem: 20
Problem Name: Factorial Digit Sum

Problem Statement:
n! means n x (n-1) x ... x 3 x 2 x 1.
For example 10! = 10 x 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/
int main()
{
    std::vector<uint8_t> digits(160, 0);
    digits[0] = 1;

    for (int i = 2; i <= 100; i++)
    {
        int carry = 0;

        for (size_t j = 0; j < digits.size(); j++)
        {
            int prod = digits[j] * i + carry;
            digits[j] = static_cast<uint8_t>(prod % 10);
            carry = prod / 10;
        }
    }

    int res = 0;
    for (uint8_t d : digits)
        res += d;

    std::cout << res << std::endl;
    // answer - 648
}