#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

std::string concatendated_product(uint32_t k, std::vector<uint8_t> &vec) {
  std::string s;
  for (uint8_t d : vec)
    s.append(std::to_string(k * d));

  return s;
}

bool is_pandigital(const std::string &s) {
  if (s.length() != 9)
    return false;

  std::string temp = s;
  std::sort(temp.begin(), temp.end());
  return temp == "123456789";
}

int main() {
  std::vector<uint8_t> nums{1};
  uint64_t max_pan = 0;

  for (uint8_t n = 2; n < 9; n++) {
    nums.push_back(n);
    for (uint32_t k = 9;; k++) {
      std::string concat = concatendated_product(k, nums);
      if (concat.length() > 9)
        break;

      if (concat.length() < 9)
        continue;

      if (is_pandigital(concat)) {
        uint64_t val = std::stoull(concat);
        if (val > max_pan)
          max_pan = val;
      }
    }
  }

  std::cout << max_pan << std::endl;
  return 0;
}
