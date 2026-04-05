#include <cstdint>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  std::vector<uint8_t> coins = {1, 2, 5, 10, 20, 50, 100, 200};
  std::vector<uint64_t> result(201, 0);
  result[0] = 1;

  for (uint8_t coin : coins)
    for (int i = coin; i <= 200; i++)
      result[i] = result[i] + result[i - coin];

  std::cout << result[200] << std::endl;
  return 0;
}
