#include <stdio.h>

int main() {
  int i, j, n;
  scanf("%d", &n);
  j = n;
  while(--j >= 0) {
    for(i=0; i<n; i++){
      if(i < j)
        printf(" ");
      else
        printf("*");
    }
    printf("\n");
  }
  return 0;
}
