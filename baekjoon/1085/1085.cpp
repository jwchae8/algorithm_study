#include <iostream>

int min(int x, int y) {
  return x > y ? y : x;
}

int main() {
  int x, y, w, h;
  std::cin >> x >> y >> w >> h;
  std::cout << min(min(x,w-x),min(y,h-y));
  return 0;
}
