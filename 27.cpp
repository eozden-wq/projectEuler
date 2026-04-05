#include <cstdint>
#include <iostream>
#include <vector>

/*
 * Euler discovered the remarkable quadratic formula:
 * n^2 + n + 41
 * It turns out that the formula will produce 40 primes for the consecutive
 * integer values 0 <= n <= 39. However, when n = 40, 40 ^ 2 + 40 + 41 =
 * 40(40+1) + 41 is divisible by 41. ...
 *
 * Find the product of the coefficients, a and b, for the quadratic expressions
 * that produces the maximum number of primes for consecutive values of n,
 * starting with n = 0;
 * */
uint64_t get_longest_run(const int a, const int b,
                         const std::vector<bool> &sieve) {
  uint64_t n = 0;
  while (sieve[(n * n) + (a * n) + b])
    n++;

  return n;
}

int main(int argc, char **argv) {
  std::vector<bool> sieve(13000, true);
  std::vector<uint16_t> primes;

  for (int i = 2; i * i < 13000; i++)
    for (int j = i * i; j < 13000; j += i)
      sieve[j] = false;

  for (uint16_t i = 2; i <= 1001; i++)
    if (sieve[i])
      primes.push_back(i);

  int best_a = 0, best_b = 0;
  uint64_t longest_run = 0;

  for (int a = 1; a <= 1000; a += 2)
    for (const int b : primes) {
      uint64_t x = get_longest_run(a, b, sieve),
               y = get_longest_run(-a, b, sieve);

      if (x > longest_run) {
        best_a = a;
        best_b = b;
        longest_run = x;
      }

      if (y > longest_run) {
        best_a = -a;
        best_b = b;
        longest_run = y;
      }
    }

  std::cout << best_a * best_b << std::endl;
  return 0;
  // answer - -59231
}
