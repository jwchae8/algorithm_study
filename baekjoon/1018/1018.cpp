#include <iostream>

int min(int x, int y) {
  return x > y ? y : x;
}

int main() {
  char board[51][51];
  int n, m, minchange = 64;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < m; j++) {
      std::cin >> board[i][j];
    }
  }
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      int tlb = 0, tlw = 0;
      for (int k = 0; k < 8; k++) {
        for (int l = 0; l < 8; l++) {
          if (board[k+i][l+j] == 'W') {
            if ((k + l) % 2 == 0) {
              tlb += 1;
            } else {
              tlw += 1;
            }
          }
          if (board[k+i][l+j] == 'B') {
            if ((k + l) % 2 == 0) {
              tlw += 1;
            } else {
              tlb += 1;
            }
          }
        }
      }
      if (minchange > min(tlb, tlw)) {
        minchange = min(tlb, tlw);
      }
    }
  }
  std::cout << minchange;
  return 0;
}
