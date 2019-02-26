#include <stdio.h>

int main() {
  int n, i=2;
  scanf("%d", &n);
  while(i*(i-1)/2 < n) i++;
  if(i%2 == 0)
    printf("%d/%d\n", i*(i-1)/2-n+1, n-i*(i-3)/2-1);
  else
    printf("%d/%d\n", n-i*(i-3)/2-1, i*(i-1)/2-n+1);
  return 0;
}
