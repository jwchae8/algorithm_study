#include <stdio.h>

int main() {
  int a, b, lcm, gcd;
  scanf("%d %d", &a, &b);
  lcm = a*b;
  while(a > 0 && b > 0) {
    a %= b;
    if(a) b %= a;
  }
  gcd = a > b ? a : b;
  printf("%d\n%d", gcd, lcm/gcd);
  return 0;
}
