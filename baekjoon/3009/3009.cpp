#include <iostream>

int main() {
  int x1, y1, x2, y2, x3, y3;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (x1 == x2) {
    std::cout << x3 << ' ';
  }
  else if (x1 == x3) {
    std::cout << x2 << ' ';
  }
  else if (x2 == x3) {
    std::cout << x1 << ' ';
  }
  if (y1 == y2) {
    std::cout << y3;
  }
  else if (y1 == y3) {
    std::cout << y2;
  }
  else if (y2 == y3) {
    std::cout << y1;
  }
  return 0;
}
