#include <cmath>
#include <cstdint>
#include <iostream>

bool is_digit_sum(uint64_t n) {
  uint64_t k = n;
  uint64_t digit_sum = 0;
  while (k) {
    digit_sum += static_cast<uint64_t>(std::pow(k % 10, 5));
    k /= 10;
  }

  return n == digit_sum;
}

int main() {
  uint64_t result = 0;
  for (uint64_t i = 10; i <= 999999; i++)
    if (is_digit_sum(i)) {
      result += i;
    }

  std::cout << result << std::endl;
  return 0;
  // answer - 443839
}
