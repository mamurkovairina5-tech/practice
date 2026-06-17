#include <iostream>
#include <string>

bool IsVehicleNumber(const std::string& number) {
  if (number.length() != 6) {
    return false;
  }
  if (number[0] < 'A' || number[0] > 'Z') {
    return false;
  }
  if (number[1] < '0' || number[1] > '9') {
    return false;
  }
  if (number[2] < '0' || number[2] > '9') {
    return false;
  }
  if (number[3] < '0' || number[3] > '9') {
    return false;
  }
  if (number[4] < 'A' || number[4] > 'Z') {
    return false;
  }
  if (number[5] < 'A' || number[5] > 'Z') {
    return false;
  }
  return true;
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