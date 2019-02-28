#include <stdio.h>

int dp[31][31];

int main() {
  int t, i, j;
  for(i=1; i<=30; i++) {
    dp[i][0] = 1; dp[i][i] = 1;
    for(j=1; j<i; j++) {
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }
  }
  scanf("%d", &t);
  while(t-- > 0) {
    scanf("%d %d", &i, &j);
    printf("%d\n", dp[j][i]);
  }
  return 0;
}
