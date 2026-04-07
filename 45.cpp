#include <cmath>
#include <cstdint>
#include <iostream>

bool is_P(uint64_t n) {
  uint64_t calc = 24ULL * n + 1;
  uint64_t root = std::sqrt(calc);
  if (root * root != calc) {
    return false;
  }
  return (root + 1) % 6 == 0;
}

bool is_T(uint64_t n) {
  uint64_t calc = 8ULL * n + 1;
  uint64_t root = std::sqrt(calc);
  if (root * root != calc)
    return false;

  return (root + 1) % 2 == 0;
}

constexpr uint64_t H(uint64_t n) { return (n * (2 * n - 1)); }

int main() {
  uint64_t n = 144;

  while (!(is_P(H(n)) && is_T(H(n)))) {
    n++;
  }

  std::cout << H(n) << std::endl;
  return 0;
}
