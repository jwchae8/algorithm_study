#include <iostream>

int main() {
  int n, cnt = 1, nums[10001], front = 0;
  while (cnt <= 10000) {
    if (front % 1000 == 666) {
      for (int i = 0; i < 1000 && cnt <= 10000; i++) {
        nums[cnt] = ((front / 1000) * 1000 + 666) * 1000 + i;
        cnt++;
      }
      front++;
      continue;
    }
    if (front % 100 == 66) {
      for (int i = 0; i < 100 && cnt <= 10000; i++) {
        nums[cnt] = ((front / 100) * 1000 + 666) * 100 + i;
        cnt++;
      }
      front++;
      continue;
    }
    else if (front % 10 == 6) {
      for (int i = 0; i < 10 && cnt <= 10000; i++) {
        nums[cnt] = ((front / 10) * 1000 + 666) * 10 + i;
        cnt++;
      }
      front++;
      continue;
    }
    nums[cnt] = front * 1000 + 666;
    cnt++;
    front++;
  }
  std::cin >> n;
  std::cout << nums[n];
  return 0;
}
