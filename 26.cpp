#include <cmath>
#include <cstdint>
#include <iostream>

uint64_t period(uint16_t n) {
  uint64_t current_rem = 10 % n;
  uint64_t k = 1;

  while (current_rem != 1 % n) {
    current_rem = (current_rem * 10) % n;
    k++;
  }

  return k;
}

int main(int argc, char **argv) {
  uint64_t result = 0;
  int result_i = 0;
  for (int i = 2; i <= 1000; i++) {
    if (i % 2 == 0 || i % 5 == 0)
      continue;

    uint64_t current_lenth = period(i);
    if (current_lenth > result) {
      result = current_lenth;
      result_i = i;
    }
  }

  std::cout << result_i << std::endl;
  return 0;
  // answer - 983
}
