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

  std::string Decryption(std::string& encrypted_word) {
    std::string decrypted_word = encrypted_word;
    for (int step = 0; step < encryption_num_; ++step) {
      std::string temp_word(word_len_, ' ');
      for (int i = 0; i < word_len_; ++i) {
        int position = permutation_[i] - 1;
        temp_word[position] = decrypted_word[i];
      }
      decrypted_word = temp_word;
    }
    return decrypted_word;
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
  std::string original_word;
  original_word = decryptor.Decryption(encrypted_word);
  std::cout << original_word << std::endl;
  return 0;
}