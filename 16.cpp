#include <iostream>
#include <vector>
#include <algorithm>

/*
Platform: Project Euler
Problem: 16
Problem Name: Power Digit Sum

Problem Statement:
2^15 = 32768 and the sum of digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of digits of the number 2^1000?
*/
int main()
{
    std::vector<int> number(1000, 0); // 2^0 -
    number[0] = 1;

    for (int i = 0; i < 1000; i++)
    {
        int carry = 0;
        for (int j = 0; j < 1000; j++)
        {
            int new_num = number[j] * 2 + carry;
            number[j] = new_num % 10;
            carry = new_num / 10;
        }
    }

    int res = 0;
    for (int i = 0; i < 1000; i++)
        res += number[i];

    std::cout << res << std::endl;
    // answer - 1366
}