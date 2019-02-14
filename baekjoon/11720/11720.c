#include <stdio.h>
int main() {
  int i, n, sum = 0;
  char d;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf(" %c", &d);
    sum += d - '0';
  }
  printf("%d\n", sum);
  return 0;
}
