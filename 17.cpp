#include <string>
#include <iostream>
#include <unordered_map>

/*
Platform: Project Euler
Problem: 17
Problem Name: Number Letter Counts

Problem Statement:
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then
there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all numbers from 1 to 1000 (one thousand) inclusive were written out in words,
how many letters would be used?

NOTE: Do not count hyphens. For example, 342 (three hundred and forty-two) contains
23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and"
when writing out numbers is in compliance with British usage.
*/
int letter_count(int n)
{
    std::unordered_map<int, int> special_cases = {
        {1, 3},
        {2, 3},
        {3, 5},
        {4, 4},
        {5, 4},
        {6, 3},
        {7, 5},
        {8, 5},
        {9, 4},
        {10, 3},
        {11, 6},
        {12, 6},
        {13, 8},
        {14, 8},
        {15, 7},
        {16, 7},
        {17, 9},
        {18, 8},
        {19, 8}};

    if (special_cases.find(n) != special_cases.end())
        return special_cases[n];

    if (n < 100)
    {
        std::unordered_map<int, int> tens = {
            {2, 6},
            {3, 6},
            {4, 5},
            {5, 5},
            {6, 5},
            {7, 7},
            {8, 6},
            {9, 6},
        };

        return tens[n / 10] + (n % 10 == 0 ? 0 : letter_count(n % 10));
    }

    if (n < 1000)
        return letter_count(n / 100) + 7 + (n % 100 == 0 ? 0 : 3 + letter_count(n % 100));

    return 11;
}

int main()
{
    int res = 0;

    for (int i = 1; i <= 1000; i++)
        res += letter_count(i);

    std::cout << res << std::endl;
    // answer - 21124
}