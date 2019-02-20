#include <stdio.h>

int triangle[500][500];
int dp[500][500];

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  int i, j, n;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    for(j=0; j<=i; j++) {
      scanf("%d", &triangle[i][j]);
    }
  }
  for(i=0; i<n; i++) {
    dp[n-1][i] = triangle[n-1][i];
  }
  for(i=n-2; i>=0; i--) {
    for(j=0; j<i+1; j++) {
      dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}
