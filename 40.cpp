#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
  uint32_t num_digits = 1, i = 1, result = 1;
  std::vector<bool> seen(7, false);

  while (num_digits <= 1000000) {
    i++;
    std::string k = std::to_string(i);
    for (char digit : k) {
      num_digits++;
      if (num_digits == 10 || num_digits == 100 || num_digits == 1000 ||
          num_digits == 10000 || num_digits == 100000 || num_digits == 1000000)
        result *= digit - '0';
    }
  }

  std::cout << result << std::endl;
  return 0;
}
