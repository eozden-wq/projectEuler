#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#define N 1000000

bool is_truncatable(uint32_t n, const std::vector<bool> &sieve) {
  if (!sieve[n])
    return false;

  uint32_t left_t = n, right_t = n;

  while (right_t) {
    if (!sieve[right_t])
      return false;
    right_t /= 10;
  }

  uint8_t num_digits = static_cast<uint8_t>(std::log10(n));

  while (left_t) {
    if (!sieve[left_t])
      return false;
    uint32_t base = 1;
    for (uint8_t i = 0; i < num_digits; i++)
      base *= 10;
    left_t %= base;
    num_digits--;
  }

  return true;
}

int main() {
  std::vector<uint32_t> primes;
  std::vector<bool> sieve(N + 1, true);
  sieve[1] = false;
  sieve[0] = false;

  for (uint32_t i = 2; i * i <= N; i++)
    if (sieve[i])
      for (uint32_t j = i * i; j <= N; j += i)
        sieve[j] = false;

  uint32_t k = 9;
  while (primes.size() < 11) {
    if (is_truncatable(k, sieve))
      primes.push_back(k);
    k += 2;
  }

  uint32_t result = 0;
  for (uint32_t prime : primes)
    result += prime;

  std::cout << result << std::endl;
  return 0;
}
