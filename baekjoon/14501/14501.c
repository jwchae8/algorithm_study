#include <stdio.h>

int dp[31];

int main() {
  int i, n, t, p;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d %d", &t, &p);
    if(dp[i] > dp[i+1])
      dp[i+1] = dp[i];
    if(dp[i+t] < dp[i] + p)
      dp[i+t] = dp[i] + p;
  }
  printf("%d\n", dp[n]);
  return 0;
}
