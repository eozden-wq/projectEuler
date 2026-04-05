#include <cstdint>
#include <iostream>

uint32_t num_solutions(uint16_t p) {
  uint32_t result = 0;

  for (int a = 1; a < p - 2; a++) {
    for (int b = a; b < p - 1; b++) {
      int c = p - (a + b);
      if (a * a + b * b == c * c)
        result++;
    }
  }

  return result;
}

int main() {
  uint32_t max_sols = 0;
  uint16_t result = 0;
  for (int p = 0; p < 1000; p++)
    if (uint32_t x = num_solutions(p); x > max_sols) {
      max_sols = x;
      result = p;
    }

  std::cout << result << std::endl;
  return 0;
}
