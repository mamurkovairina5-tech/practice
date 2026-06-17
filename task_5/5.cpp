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
  int min_column = width;
  int max_column = -1;
  int min_row = height;
  int max_row = -1;
  for (int row = 0; row < height; ++row) {
    for (int column = 0; column < width; ++column) {
      if (matrix[row][column] == 1) {
        if (row < min_row) {
          min_row = row;
        }
        if (row > max_row) {
          max_row = row;
        }
        if (column < min_column) {
          min_column = column;
        }
        if (column > max_column) {
          max_column = column;
        }
      }
    }
  }
  std::cout << min_row - 1 << " " << min_column - 1 << " " << max_row + 1 << " " << max_column + 1 << std::endl;
  return 0;
}