#include <iostream>

bool prime[10001];
int main() {
  prime[1] = 1;
  for (int i = 2; i <= 5000; i++) {
    for (int j = 2; i * j <= 10000; j++) {
      prime[i * j] = 1;
    }
  }
  int t, n;
  std::cin >> t;
  while (t-- > 0) {
    std::cin >> n;
    for (int i = n / 2; i >= 2; i--) {
      if (!prime[i] && !prime[n - i]) {
        std::cout << i << ' ' << n - i << std::endl;
        break;
      }
    }
  }
  return 0;
}
