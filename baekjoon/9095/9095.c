#include <stdio.h>
#include <string.h>

int dp[11];

int solve(int n) {
  if(n < 0)
    return 0;
  if(n == 0)
    return 1;
  if(dp[n-1] != -1)
    return dp[n-1];
  dp[n-1] = solve(n-3) + solve(n-2) + solve(n-1);
  return dp[n-1];
}

int main() {
  int i, t, n;
  scanf("%d", &t);
  for(i=0; i<t; i++) {
    scanf("%d", &n);
    memset(dp, -1, sizeof(int) * 11);
    printf("%d\n", solve(n));
  }
  return 0;
}
