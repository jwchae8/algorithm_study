#include <iostream>

bool prime[300000];
int main() {
  prime[1] = 1;
  for (int i = 2; i < 150000; i++) {
    for (int j = 2; i * j < 300000; j++) {
      prime[i * j] = 1;
    }
  }
  int n;
  std::cin >> n;
  while (n != 0) {
    int cnt = 0;
    for (int i = n + 1; i <= 2*n; i++) {
      if (!prime[i]) {
        cnt++;
      }
    }
    std::cout << cnt << std::endl;
    std::cin >> n;
  }
  return 0;
}
