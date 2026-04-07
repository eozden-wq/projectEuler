#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int word_value(std::string str) {
  int result = 0;
  for (const char letter : str)
    result += (int)(letter - 'A' + 1);

  return result;
}

bool is_triangle_number(int n) {
  int x = 8 * n + 1;
  long root = std::sqrt(x);
  return root * root == x;
}

int main() {
  std::vector<std::string> words;

  std::ifstream fstream("files/42.txt");

  std::string str_words;
  std::getline(fstream, str_words);

  std::stringstream stream(str_words);
  std::string intermediate;

  while (std::getline(stream, intermediate, ','))
    words.push_back(intermediate);

  std::vector<std::string>::iterator it;
  for (it = words.begin(); it != words.end(); it++)
    *it = it->substr(1, it->size() - 2);

  int result = 0;
  for (std::string word : words)
    if (is_triangle_number(word_value(word)))
      result++;

  std::cout << result << std::endl;
  return 0;
}
