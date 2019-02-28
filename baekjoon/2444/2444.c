#include <stdio.h>

int abs(int x) {
  return x > 0 ? x : -x;
}

int main() {
  int i, j, n;
  scanf("%d", &n);
  for(i=-n+1; i<=n-1; i++) {
    for(j=0; j<abs(i); j++)
      printf(" ");
    for(j=0; j<2 * (n - abs(i)) - 1; j++)
      printf("*");
    printf("\n");
  }
  return 0;
}
