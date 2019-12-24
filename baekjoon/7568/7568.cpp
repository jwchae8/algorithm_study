#include <iostream>
#include <tuple>

int main() {
  int n, rank[50];
  std::pair<int, int> d[50];
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> d[i].first >> d[i].second;
    rank[i] = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (d[i].first > d[j].first && d[i].second > d[j].second) {
        rank[j]++;
      }
      if (d[i].first < d[j].first && d[i].second < d[j].second) {
        rank[i]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << rank[i] << ' ';
  }
  return 0;
}
