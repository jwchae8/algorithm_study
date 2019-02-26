#include <stdio.h>

int main() {
  int i, j, n;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    for(j=n-i; j>1; j--) {
      printf(" ");
    }
    for(j=1; j<=2*i+1; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
