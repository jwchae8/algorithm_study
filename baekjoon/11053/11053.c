#include <stdio.h>

int dp[1001];

int main() {
  int i, j, n, arr[1001], max=1, total_max=1;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", arr+i);
  }
  dp[0] = 1;
  for(i=1; i<n; i++) {
    max = 0;
    for(j=0; j<i; j++) {
      if(arr[j] < arr[i] && max < dp[j]) {
        max = dp[j];
      }
    }
    dp[i] = max+1;
    if(dp[i] > total_max)
      total_max = dp[i];
  }
  printf("%d\n", total_max);
  return 0;
}
