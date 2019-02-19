#include <stdio.h>

int dp[1000][3];
int cost[1000][3];

int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
  }
  dp[0][0] = cost[0][0];
  dp[0][1] = cost[0][1];
  dp[0][2] = cost[0][2];
  for(i=1; i<n; i++) {
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
  }
  printf("%d\n", min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]));
  return 0;
}
