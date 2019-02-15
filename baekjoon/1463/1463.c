#include <stdio.h>
#include <string.h>

int dp[1000000];

int solve(int n) {
  int three = 999999, two = 999999, one = 999999;
  if(n == 1)
    return 0;
  if(dp[n-1] != -1)
    return dp[n-1];
  if(n % 3 == 0)
    three = solve(n / 3) + 1;
  if(n % 2 == 0)
    two = solve(n / 2) + 1;
  one = solve(n - 1) + 1;
  if(three >= one && two >= one)
    dp[n-1] = one;
  else if(three >= two && one >= two)
    dp[n-1] = two;
  else
    dp[n-1] = three;
  return dp[n-1];
}

int main() {
  int x;
  scanf("%d", &x);
  memset(dp, -1, 1000000 * sizeof(int));
  printf("%d\n", solve(x));
  return 0;
}
