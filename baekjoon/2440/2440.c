#include <stdio.h>

int main() {
  int i, n;
  scanf("%d", &n);
  while(n-- >= 0) {
    for(i=0; i<=n; i++)
      printf("*");
    printf("\n");
  }
  return 0;
}
