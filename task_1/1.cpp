#include <iostream>
#include <vector>

void FindShortestPath(std::vector<std::vector<int>>& pyramid, int n) {
  // dp[row][column] хранит минимальное время спуска до данной ячейки
  std::vector<std::vector<int>> dp(n);
  // parent[row][column] хранит координаты {row, column} ячейки, из которой пришли
  std::vector<std::vector<std::pair<int, int>>> parent(n);
  const int INF = 1e9;
  for (int row = 0; row < n; ++row) {
    dp[row].resize(row + 1, INF);
    parent[row].resize(row + 1, {-1, -1});
  }
  dp[0][0] = pyramid[0][0];

  // Послойный расчет минимального времени спуска сверху вниз
  for (int row = 0; row < n - 1; ++row) {
    for (int column = 0; column <= row; ++column) {
      if (dp[row][column] == INF) {
        continue;
      }
      int next_row = row + 1;

      //Шаг вниз (в ту же колонку column)
      int next_column = column;
      int time_column = dp[row][column] + pyramid[next_row][next_column];
      if (time_column < dp[next_row][next_column]) {
        dp[next_row][next_column] = time_column;
        parent[next_row][next_column] = {row, column};
      }

      // Шаг вниз-направо (в колонку column + 1)
      int next_column_right = column + 1;
      int time_column_right = dp[row][column] + pyramid[next_row][next_column_right];
      if (time_column_right < dp[next_row][next_column_right]) {
        dp[next_row][next_column_right] = time_column_right;
        parent[next_row][next_column_right] = {row, column};
      }
    }
  }
}

int main() {
  int pyramid_height = 0;
  std::cin >> pyramid_height;

  std::vector<std::vector<int>> pyramid(pyramid_height);
  for(int row = 0; row < pyramid_height; ++row) {
    pyramid[row].resize(row + 1);
    for (int column = 0; column <= row; ++column) {
      std::cin >> pyramid[row][column];
    }
  }

  FindShortestPath(pyramid, pyramid_height);
  return 0;
}