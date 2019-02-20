#include <stdio.h>

int wines[10001];
int dp[10001][3];

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i=1; i<=n; i++) {
    scanf("%d", wines + i);
  }
  dp[1][1] = wines[1];
  for(i=2; i<=n; i++) {
    dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    dp[i][1] = max(max(dp[i-2][0], dp[i-2][1]), dp[i-2][2]) + wines[i];
    dp[i][2] = dp[i-1][1] + wines[i];
  }
  printf("%d\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
  return 0;
}
