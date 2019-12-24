#include <iostream>

int main() {
  int i, n, generator;
  std::cin >> n;
  for (i = 1; i < n; i++) {
    int sum = i;
    int tmp = i;
    while (tmp) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (sum == n) {
      generator = i;
      break;
    }
  }
  if (i == n) {
    std::cout << 0;
  }
  else {
    std::cout << generator;
  }
  return 0;
}
