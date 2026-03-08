#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(int num)
{
    std::string s = std::to_string(num);
    std::string rev = s;
    std::reverse(rev.begin(), rev.end());
    return s == rev;
}

int main()
{
    int res = 0;
    for (int i = 999; i >= 100; i--)
        for (int j = 999; j >= 100; j--)
            if (isPalindrome(i * j))
                res = std::max(res, i * j);

    std::cout << res << std::endl;
    return 0;
}
