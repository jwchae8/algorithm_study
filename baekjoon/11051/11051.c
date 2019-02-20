#include <stdio.h>
#include <string.h>

int dp[1001][1001];

int combination(int n, int k) {
  if(n < 0 || k > n)
    return 0;
  if(n == k || k == 0)
    return 1;
  if(dp[n][k] != -1)
    return dp[n][k];
  dp[n][k] = (combination(n-1, k-1) % 10007 + combination(n-1, k) % 10007) % 10007;
  return dp[n][k];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  memset(dp, -1, sizeof(int) * 1001 * 1001);
  printf("%d\n", combination(n, k));
  return 0;
}
