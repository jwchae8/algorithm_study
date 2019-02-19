#include <stdio.h>

unsigned long long int dp[100];

int main() {
  int i, j, n;
  scanf("%d", &n);
  dp[1] = 1;
  dp[2] = 1;
  for(i=3; i<=n; i++) {
    dp[i] = 1;
    for(j=1; j<=i-2; j++) {
      dp[i] += dp[j];
    }
  }
  printf("%llu\n", dp[n]);
  return 0;
}
