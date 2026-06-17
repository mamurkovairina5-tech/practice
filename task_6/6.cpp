#include <iostream>
#include <vector>

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