#include <iostream>
#include <vector>
#include <string>

class Decryptor {
 private:
  int word_len_;
  int encryption_num_;
  std::vector<int> permutation_;

 public:
  Decryptor(int n, int k, std::vector<int>& p) {
    word_len_ = n;
    encryption_num_ = k;
    permutation_ = p;
  }
};

int main() {
  int len = 0;
  int count_iterations = 0;
  std::cin >> len >> count_iterations;
  std::vector<int> permutation(len);
  for (int i = 0; i < len; ++i) {
    std::cin >> permutation[i];
  }
  std::string encrypted_word;
  std::cin >> encrypted_word;
  Decryptor decryptor(len, count_iterations, permutation);
  return 0;
}