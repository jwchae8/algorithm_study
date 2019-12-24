#include <iostream>

int main() {
  int x, y, z;
  std::cin >> x >> y >> z;
  while (x != 0 || y != 0 || z != 0) {
    if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x) {
      std::cout << "right" << std::endl;
    }
    else {
      std::cout << "wrong" << std::endl;
    }
    std::cin >> x >> y >> z;
  }
  return 0;
}
