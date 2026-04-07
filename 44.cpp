#include <cmath>
#include <cstdint>
#include <iostream>

constexpr uint64_t P(uint64_t n) { return (n * (3 * n - 1)) >> 1; }

bool is_P(uint64_t n) {
  uint64_t calc = 24ULL * n + 1;
  uint64_t root = std::sqrt(calc);
  if (root * root != calc) {
    return false;
  }
  return (root + 1) % 6 == 0;
}

int main() {
  uint64_t D_min = UINT64_MAX;

  // for mathematical rigour.
  for (uint32_t n = 2; P(n) - P(n - 1) < D_min; n++) {
    for (uint32_t m = n - 1; m > 0; m--) {
      uint64_t diff = P(n) - P(m);
      if (diff >= D_min)
        break;

      if (is_P(diff) && is_P(P(n) + P(m)))
        D_min = P(n) - P(m);
    }
  }

  std::cout << D_min << std::endl;
  return 0;
}
