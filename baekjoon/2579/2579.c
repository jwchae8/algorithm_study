#include <stdio.h>
#include <string.h>

int stairs[301];
int dp[301][2];

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i=1; i<=n; i++) {
    scanf("%d", stairs+i);
  }
  dp[1][0] = stairs[1];
  dp[2][0] = stairs[2];
  dp[2][1] = stairs[1] + stairs[2];
  for(i=3; i<=n; i++) {
    dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + stairs[i];
    dp[i][1] = max(dp[i-3][0], dp[i-3][1]) + stairs[i-1] + stairs[i];
  }
  printf("%d\n",max(dp[n][0], dp[n][1]));
  return 0;
}
