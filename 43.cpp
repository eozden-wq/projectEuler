#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

bool has_property(std::vector<uint8_t> &nums) {
  std::vector<uint8_t> primes = {2, 3, 5, 7, 11, 13, 17};

  for (int k = 1; k < 8; k++) {
    int n = 0;
    for (int i = k; i < k + 3; i++) {
      n *= 10;
      n += nums[i];
    }
    if ((n % primes[k - 1]) != 0)
      return false;
  }
  return true;
}

uint64_t to_num(std::vector<uint8_t> &nums) {
  uint64_t result = 0;
  for (const uint8_t &digit : nums) {
    result *= 10;
    result += digit;
  }

  return result;
}

int main() {
  std::vector<uint8_t> nums = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
  uint64_t result = 0;

  do {
    if (has_property(nums)) {
      result += to_num(nums);
    }
  } while (std::next_permutation(nums.begin(), nums.end()));

  std::cout << result << std::endl;
  return 0;
}
