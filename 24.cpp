#include <cstdint>
#include <iostream>
#include <vector>

/*
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3, and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexicographic order. The
 * lexicographic permutations of 0, 1, and 2 are: 012 021 102 120 201 210
 *
 * What is the millionth lexicographic permutation of the digits
 * 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9
 * */
uint32_t factorial(uint8_t n) {
  uint32_t result = 1;

  for (int i = 1; i <= n; i++)
    result *= i;

  return result;
}

uint8_t get_kth_digit(std::vector<uint8_t> &ordering, uint8_t k) {
  uint8_t i = 0;
  uint8_t result = 0;
  while (i < 10 && k > 0) {
    i++;
    if (ordering[i] != 255)
      k--;
  }

  result = ordering[i];
  ordering[i] = 255;
  return result;
}

int main(int argc, char **argv) {
  uint64_t result = 0;
  uint32_t n = 9, permutation = 999999;
  std::vector<uint8_t> ordering{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  while (n > 0) {
    uint8_t k = permutation / factorial(n);
    permutation %= factorial(n);
    result += get_kth_digit(ordering, k);
    result *= 10;
    n--;
  }

  std::cout << result << std::endl;
  return 0;
  // answer - 2783915460
}
