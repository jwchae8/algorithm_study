#include <iostream>

int main() {
  int n, m, cards[100], max = -1;
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    std::cin >> cards[i];
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = cards[i] + cards[j] + cards[k];
        if (sum > max && sum <= m) {
          max = sum;
        }
      }
    }
  }
  std::cout << max;
  return 0;
}
