#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

/*
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than
 * n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than the limit.
 *
 * Find the sum of positive integers which cannot be written as the sum of two
 * abundant numbers
 * */

bool two_summable(const std::vector<uint32_t> &nums, uint32_t target) {
  for (uint32_t i = 1; i <= target; i++)
    if (nums[i] > i && nums[target - i] > target - i)
      return true;
  return false;
}

void populate_divisor_sums(std::vector<uint32_t> &divisor_sums) {
  for (int i = 1; i <= 28123; i++)
    for (int j = 2 * i; j <= 28123; j += i)
      divisor_sums[j] += i;
}

int main() {
  uint64_t result = 0;
  std::vector<uint32_t> divisor_sums(281234, 0);

  populate_divisor_sums(divisor_sums);

  for (int i = 1; i <= 28123; i++)
    if (!two_summable(divisor_sums, i))
      result += i;

  std::cout << result << std::endl;
  // answer - 4179871
}
