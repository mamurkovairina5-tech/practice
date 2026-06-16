#include <iostream>
#include <vector>

class SnowTracker {
 private:
  int num_streets_;
  std::vector<int64_t> streets_;

 public:
  SnowTracker(int n) {
    num_streets_ = n;
    streets_.resize(n + 1, 0);
  }

  void AddSnow(int street_id, int64_t snow) {
    streets_[street_id] += snow;
  }

  int64_t TotalSnow(int start_index, int end_index) {
    int64_t total_snow = 0;
    for (int i = start_index; i <= end_index; ++i) {
      total_snow += streets_[i];
    }
    return total_snow;
  }
};

int main() {
  int num_streets = 0;
  int num_requests = 0;
  std::cin >> num_streets >> num_requests;
  SnowTracker tracker(num_streets);
  for(int i = 0; i < num_requests; ++i) {
    int type = 0;
    std::cin >> type;
    if (type == 1) {
      int street_id = 0;
      int64_t snow = 0;
      std::cin >> street_id >> snow;
      tracker.AddSnow(street_id, snow);
    } else if (type == 2) {
      int start_id = 0;
      int end_id = 0;
      std::cin >> start_id >> end_id;
      std::cout << tracker.TotalSnow(start_id, end_id) << std::endl;
    }
  }
  return 0;
}