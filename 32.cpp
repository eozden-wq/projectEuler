#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

// Return -1 if not pandigital, otherwise return product
int is_permutation_pandigital(const std::vector<uint8_t> &digits,
                              uint8_t cutoff) {
  uint32_t a = 0, b = 0, p = 0;

  for (uint8_t i = 0; i < 9; i++) {
    if (i < cutoff) {
      a *= 10;
      a += digits[i];
    } else if (i < 5) {
      b *= 10;
      b += digits[i];
    } else {
      p *= 10;
      p += digits[i];
    }
  }

  return a * b == p ? p : -1;
}

int main() {
  std::vector<uint8_t> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::set<uint32_t> seen_products;
  uint64_t result = 0;

  while (std::next_permutation(digits.begin(), digits.end())) {
    int product1 = is_permutation_pandigital(digits, 2),
        product2 = is_permutation_pandigital(digits, 1);

    if (product1 != -1 && seen_products.count(product1) == 0) {
      seen_products.emplace(product1);
      result += product1;
    }

    if (product2 != -1 && seen_products.count(product2) == 0) {
      seen_products.emplace(product2);
      result += product2;
    }
  }

  std::cout << result << std::endl;
  return 0;
}
