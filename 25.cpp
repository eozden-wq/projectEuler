#include <cstdint>
#include <iostream>
#include <vector>

/*
 * The fibonacci sequence is defined by the recurrence relation:
 *  F_n = F_{n-1} + F_{n-2}, where F_1 = 1 and F_2 = 1
 *
 * What is the index of the first term in the Fibonacci sequence to contain
 * 1000 digits
 * */
std::vector<uint8_t> add_vector_ints(const std::vector<uint8_t> &a,
                                     const std::vector<uint8_t> &b) {
  std::vector<uint8_t> result(1000, 0);

  uint8_t carry = 0;
  for (int i = 0; i < 1000; i++) {
    result[i] = (a[i] + b[i] + carry) % 10;
    carry = (a[i] + b[i] + carry) / 10;
  }

  return result;
}

int main() {
  std::vector<uint8_t> a(1000, 0);
  std::vector<uint8_t> b(1000, 0);
  std::vector<uint8_t> c(1000, 0);
  b[0] = 1;
  c[0] = 1;

  uint64_t i = 2;
  while (c[999] == 0) {
    i++;
    a = b;
    b = c;
    std::vector<uint8_t> res = add_vector_ints(a, b);
    std::copy(res.begin(), res.end(), c.begin());
  }

  std::cout << i << std::endl;
  return 0;
  // answer - 4782
}
