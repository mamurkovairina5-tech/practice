#include <iostream>
#include <vector>

class Graph {
 private:
  int num_verticies_;
  std::vector<std::vector<int>> adjacency_list_;
  std::vector<bool> visited_;

  std::vector<int>& GetChildren(int vertex) {
    return adjacency_list_[vertex];
  }

  void DFS(int v) {
    visited_[v] = true;
    std::vector<int>& children = GetChildren(v);
    for (size_t i = 0; i < children.size(); ++i) {
      int ch = children[i];
      if (visited_[ch] == false) {
        DFS(ch);
      }
    }
  }

 public:
  Graph(int n) {
    num_verticies_ = n;
    adjacency_list_.resize(n + 1);
    visited_.resize(n + 1, false);
  }

  void AddEdge(int from, int to) {
    adjacency_list_[from].push_back(to);
    adjacency_list_[to].push_back(from);
  }

  int CountNeededEdges() {
    int num_components = 0;
    for (size_t i = 1; i <= num_verticies_; ++i) {
      if (visited_[i] == false) {
        num_components++;
        DFS(i);
      }
    }
    return num_components - 1;
  }
};

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  for (int i = 0; i < m; ++i) {
    int from = 0;
    int to = 0;
    std::cin >> from >> to;
    graph.AddEdge(from, to);
  }
  std::cout << graph.CountNeededEdges() << std::endl;
  return 0;
}