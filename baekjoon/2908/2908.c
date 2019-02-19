#include <stdio.h>

int main() {
  int x, y, a, b;
  scanf("%d %d", &x, &y);
  a = x;
  b = y;
  while(1) {
    if(a % 10 > b % 10) {
      printf("%d\n", x / 100 + (x % 10) * 100 + ((x / 10) % 10) * 10) ;
      break;
    } else if(a % 10 < b % 10) {
      printf("%d\n", y / 100 + (y % 10) * 100 + ((y / 10) % 10) * 10);
      break;
    } else {
      a /= 10;
      b /= 10;
    }
  }
  return 0;
}
