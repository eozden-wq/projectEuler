#include <iostream>

/*
Platform: Project Euler
Problem: 19
Problem Name: Counting Sundays

Problem Statement:
You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.
- leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/
int main()
{
    // 1st Jan, 1901 - Tuesday
    // Weeks start from Sunday
    int day = 0, month = 0, year = 1900, day_of_week = 1;
    int result = 0;

    while (day != 30 || month != 11 || year != 2000)
    {
        if (day == 0 && day_of_week == 0 && year >= 1901)
            result++;

        day += 1;
        day_of_week = (day_of_week + 1) % 7;

        if (month == 3 || month == 5 || month == 8 || month == 10)
            day %= 30;
        else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 11 || month == 9)
            day %= 31;
        else if (!(year % 4))
        {
            if (!(year % 100))
            {
                if (!(year % 400))
                    day %= 29;
                else
                    day %= 28;
            }
            else
            {
                day %= 29;
            }
        }
        else
            day %= 28;

        if (day == 0)
        {
            month++;
            if (!(month % 12))
            {
                year++;
                month = 0;
            }
        }
    }

    std::cout << result << std::endl;
    // answer - 171
}