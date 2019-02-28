#include <stdio.h>

int dp[1001];
int p[1001];

int main() {
  int i, j, n;
  scanf("%d", &n);
  for(i=1; i<=n; i++)
    scanf("%d", p+i);
  dp[1] = p[1];
  for(i=2; i<=n; i++) {
    dp[i] = p[i];
    for(j=1; j<i; j++) {
      if(dp[i] < dp[j] + p[i-j])
        dp[i] = dp[j] + p[i-j];
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
