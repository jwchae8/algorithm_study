#include <stdio.h>

int main() {
  int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int a, b, c;
  scanf("%d\n%d\n%d", &a, &b, &c);
  c = a * b * c;
  while(c != 0) {
    digits[c%10]++;
    c /= 10;
  }
  for(a = 0; a < 10; a++) {
    printf("%d\n", digits[a]);
  }
  return 0;
}
