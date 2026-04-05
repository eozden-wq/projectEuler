#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#define N 1000000

bool is_circular_prime(uint32_t n, std::vector<bool> &sieve) {
  std::string s = std::to_string(n);
  if (s.length() <= 1)
    return sieve[n];

  s = s.substr(1) + s[0];
  uint32_t rotated = std::stoi(s);
  while (n != rotated && sieve[rotated]) {
    s = s.substr(1) + s[0];
    rotated = std::stoi(s);
  }

  return rotated == n;
}

int main() {
  std::vector<bool> sieve(N + 1, true);
  sieve[0] = sieve[1] = false;
  uint32_t result = 0;

  for (int i = 2; i * i <= N; i++)
    if (sieve[i])
      for (int j = i * i; j <= N; j += i)
        sieve[j] = false;

  for (uint32_t i = 1; i <= N; i++)
    if (sieve[i] && is_circular_prime(i, sieve))
      result++;

  std::cout << result << std::endl;
  return 0;
}
