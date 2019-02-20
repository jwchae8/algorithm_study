#include <stdio.h>

int main() {
  int n, k;
  int i, num=1, dem=1;
  scanf("%d %d", &n, &k);
  for(i=1; i<=k; i++) {
    num *= (n+1-i);
    dem *= i;
  }
  printf("%d\n", num/dem);
  return 0;
}
