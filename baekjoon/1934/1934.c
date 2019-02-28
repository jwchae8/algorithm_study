#include <stdio.h>

int main() {
  int t, a, b, lcm;
  scanf("%d", &t);
  while(t-- > 0) {
    scanf("%d %d", &a, &b);
    lcm = a * b;
    while(a > 0 && b > 0) {
      if(a > b)
        a %= b;
      else
        b %= a;
    }
    lcm /= a > b ? a : b;
    printf("%d\n", lcm);
  }
  return 0;
}
