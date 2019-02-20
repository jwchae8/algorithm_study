#include <stdio.h>

int dp[100001];

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  int i, n, num, maxsum = -999999;
  scanf("%d", &n);
  scanf("%d", &dp[1]);
  for(i=2; i<=n; i++) {
    scanf("%d", &num);
    dp[i] = dp[i-1] + num > num ? dp[i-1] + num : num;
  }
  for(i=1; i<=n; i++) {
    if(maxsum < dp[i])
      maxsum = dp[i];
  }
  printf("%d\n", maxsum);
  return 0;
}
