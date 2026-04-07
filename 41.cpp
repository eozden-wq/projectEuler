#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define MAX_PANDIGITAL 9999999

uint32_t to_num(std::vector<uint8_t> &nums) {
  uint32_t result = 0;
  for (const uint8_t num : nums) {
    result *= 10;
    result += num;
  }

  return result;
}

int main() {
  std::vector<uint8_t> nums = {1, 2, 3, 4, 5, 6, 7};
  std::vector<bool> sieve(MAX_PANDIGITAL + 1, true);
  sieve[0] = false;
  sieve[1] = false;

  for (int i = 2; i * i <= MAX_PANDIGITAL; i++)
    if (sieve[i])
      for (int j = i * i; j <= MAX_PANDIGITAL; j += i)
        sieve[j] = false;

  uint32_t result = 0;
  do {
    if (sieve[to_num(nums)] && to_num(nums) > result)
      result = to_num(nums);
  } while (std::next_permutation(nums.begin(), nums.end()));

  std::cout << result << std::endl;
  return 0;
}
