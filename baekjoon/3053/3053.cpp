#include <iostream>

int main() {
  int r;
  std::cin >> r;
  std::cout.precision(6);
  std::cout.setf(std::ios::fixed);
  double area1 = 3.141592653589793 * r * r;
  double area2 = 2 * r * r;
  std::cout << area1 << std::endl << area2;
  return 0;
}
