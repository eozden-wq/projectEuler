#include <cstdint>
#include <iostream>
#include <vector>

#define N 1001

/*
 * Starting with the number of 1 and moving to the right in a clockwise
 * direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20 7  8  9  10
 * 19 6  1  2  11
 * 18 5  4  3  12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the diagonals is 101.
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way.
 * */
int main() {
  std::vector<std::vector<uint32_t>> spiral(N, std::vector<uint32_t>(N, 0));

  uint32_t result = 0;

  short di = 0, dj = -1;
  int i = 0, j = N - 1;
  uint32_t m = N * N;

  while (i != 500 || j != 500) {
    spiral[i][j] = m;
    m--;

    if (i + di >= N || j + dj >= N || j + dj < 0 ||
        spiral[i + di][j + dj] != 0) {
      short di_n = -dj, dj_n = di;
      dj = dj_n;
      di = di_n;
    }

    i += di;
    j += dj;
  }

  for (int i = 0; i < N; i++) {
    result += spiral[i][i];
    result += spiral[i][N - i - 1];
  }

  result++;

  std::cout << result << std::endl;
  return 0;
  // answer - 669171001
}
