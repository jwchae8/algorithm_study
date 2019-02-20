#include <stdio.h>

int dp[1000][10];
int main() {
  int i, j, n, sum=0;
  scanf("%d", &n);
  for(i=0; i<10; i++) {
    dp[0][i] = 1;
  }
  for(i=1; i<n; i++) {
    for(j=0; j<10; j++) {
      if(j-1 >= 0)
        dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % 1000000000;
      if(j+1 <= 9)
        dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % 1000000000;
    }
  }
  for(i=1; i<10; i++) {
    sum = (sum + dp[n-1][i]) % 1000000000 ;
  }
  printf("%d\n", sum);
  return 0;
}
