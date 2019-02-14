#include <stdio.h>

int main(){
  int i, j = 0, n;
  scanf("%d", &n);
  while(j++ < n) {
    for(i=1; i<=n; i++){
      if(i < j)
        printf(" ");
      else
        printf("*");
    }
    printf("\n");
  }
  return 0;
}
