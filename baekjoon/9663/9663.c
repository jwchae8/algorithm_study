#include <stdio.h>

int n;
int board[15][15];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int nq(int row) {
  int i, j, k, ret = 0;
  if(row == n)
    return 1;
  for(i=0; i<n; i++) {
    if(!board[row][i]) {
      board[row][i]++;
      for(j=0; j<8; j++) {
        k = 1;
        while(row + dy[j] * k >= 0 && row + dy[j] * k < n && i + dx[j] * k >= 0 && i + dx[j] * k < n) {
          board[row + dy[j] * k][i + dx[j] * k]++;
          k++;
        }
      }
      ret += nq(row+1);
      board[row][i]--;
      for(j=0; j<8; j++) {
        k = 1;
        while(row + dy[j] * k >= 0 && row + dy[j] * k < n && i + dx[j] * k >= 0 && i + dx[j] * k < n) {
          board[row + dy[j] * k][i + dx[j] * k]--;
          k++;
        }
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  printf("%d\n", nq(0));
  return 0;
}
