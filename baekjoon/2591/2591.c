#include <stdio.h>

int main() {
  int i, dp[50], n;
  char num[50];
  scanf("%s", num+1);
  dp[0] = 1;
  for(i=1; num[i]; i++) {
    n = num[i] - '0'; dp[i] = 0;
    if(n > 0) dp[i] += dp[i-1];
    if(i > 1 && (num[i-1] - '0') && n + 10 * (num[i-1] - '0') <= 34) dp[i] += dp[i-2];
  }
  printf("%d\n", dp[i-1]);
  return 0;
}
