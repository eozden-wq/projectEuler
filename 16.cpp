#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
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