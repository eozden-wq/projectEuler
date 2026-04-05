#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

struct Fraction {
  uint64_t numerator;
  uint64_t denominator;

  bool is_trivial() { return numerator % 10 == 0 && denominator % 10 == 0; }
  bool operator==(const Fraction &other) const {
    return (other.numerator == numerator && other.denominator == denominator);
  }
  Fraction operator*(const Fraction &other) const {
    return (Fraction){numerator * other.numerator,
                      denominator * other.denominator};
  }

  friend std::ostream &operator<<(std::ostream &os, const Fraction &obj) {
    os << obj.numerator << "/" << obj.denominator;
    return os;
  }
};

Fraction reduce(Fraction x) {
  int common = std::gcd(x.numerator, x.denominator);
  return (Fraction){static_cast<uint8_t>(x.numerator / common),
                    static_cast<uint8_t>(x.denominator / common)};
}
Fraction digit_reduce(Fraction x) {
  uint8_t n_t = x.numerator / 10,
          n_u = x.numerator % 10, // numerator tens, numerator units
      d_t = x.denominator / 10,
          d_u = x.denominator % 10; // denominator tens, denominator units

  if (n_t == d_u && n_u < d_t)
    return (Fraction){n_u, d_t};
  if (n_t == d_t && n_u < d_u)
    return (Fraction){n_u, d_u};
  if (n_u == d_t && n_t < d_u)
    return (Fraction){n_t, d_u};
  if (n_u == d_u && n_t < d_t)
    return (Fraction){n_t, d_t};
  return (Fraction){1, 0};
}

int main() {
  std::vector<Fraction> fractions;
  for (uint8_t num = 10; num <= 99; num++) {
    for (uint8_t denom = num + 1; denom <= 99; denom++) {
      Fraction x = {num, denom};
      if (x.is_trivial())
        continue;
      if (reduce(x) == reduce(digit_reduce(x)))
        fractions.push_back(x);
    }
  }

  Fraction result = {1, 1};
  for (const Fraction &f : fractions)
    result = result * f;

  std::cout << reduce(result).denominator << std::endl;
  return 0;
}
