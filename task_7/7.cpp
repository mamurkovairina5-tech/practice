#include <iostream>
#include <string>

bool IsVehicleNumber(std::string& number) {
  return false;
}

int main() {
  std::string number;
  std::cin >> number;
  if (IsVehicleNumber(number)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}