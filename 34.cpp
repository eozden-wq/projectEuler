#include <cstdint>
#include <iostream>

uint32_t factorial(uint32_t n) {
  if (n == 0 || n == 1)
    return 1;
  uint32_t result = 1;
  for (uint32_t i = 1; i <= n; i++)
    result *= i;
  return result;
}

bool is_curious(uint32_t n) {
  uint32_t digit_factorial_sum = 0;
  uint32_t k = n;

  while (k) {
    digit_factorial_sum += factorial(k % 10);
    k /= 10;
  }

  return digit_factorial_sum == n;
}

int main() {
  uint32_t result = 0;
  for (uint32_t i = 3; i < 10000000; i++)
    if (is_curious(i))
      result += i;

  std::cout << result << std::endl;
}
