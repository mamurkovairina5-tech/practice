#include <iostream>
#include <vector>

int main() {
  int height = 0;
  int width = 0;
  std::cin >> height >> width;
  std::vector<std::vector<int>> matrix(height, std::vector<int>(width));
  for (int row = 0; row < height; ++row) {
    for (int column = 0; column < width; ++column) {
      std::cin >> matrix[row][column];
    }
  }
  return 0;
}