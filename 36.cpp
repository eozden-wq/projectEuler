#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

std::string convert_base_2(uint32_t n) {
  if (n == 0)
    return "0";

  std::string result = "";

  while (n > 0) {
    result += std::to_string(n % 2);
    n /= 2;
  }

  std::reverse(result.begin(), result.end());
  return result;
}

bool is_base_2_pallindromic(uint32_t n) {
  std::string reversed = convert_base_2(n);
  std::reverse(reversed.begin(), reversed.end());
  return convert_base_2(n) == reversed;
}

bool is_base_10_pallindromic(uint32_t n) {
  std::string reversed = std::to_string(n);
  std::reverse(reversed.begin(), reversed.end());
  return reversed == std::to_string(n);
}

int main() {
  uint64_t result = 0;

  for (uint32_t i = 0; i < 1000000; i++)
    if (is_base_10_pallindromic(i) && is_base_2_pallindromic(i))
      result += i;

  std::cout << result << std::endl;
  return 0;
}
