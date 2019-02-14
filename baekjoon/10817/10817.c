#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if((a >= b && b >= c) || (a <= b && b <= c))
    printf("%d\n", b);
  else if((a >= c && c >= b) || (a <= c && c <= b))
    printf("%d\n", c);
  else if((b >= a && a >= c) || (b <= a && a <= c))
    printf("%d\n", a);
  return 0;
}
