#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int num_requests = 0;
  std::cin >> num_requests;
  std::vector<int> result(num_requests, 0);
  for (int i = 0; i < num_requests; ++i) {
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    std::cin >> a >> b >> x >> y;
    int pairs_a = 0;
    int pairs_b = 0;
    pairs_b = std::min(b, x);
    x -= pairs_b;
    pairs_a = std::min(a, x + y);
    result[i] = pairs_a + pairs_b;
  }
  for (int i = 0; i < num_requests; ++i) {
    if (i == num_requests - 1) {
      std::cout << result[i] << std::endl;
    } else {
      std::cout << result[i] << " ";
    }
  }
  return 0;
}