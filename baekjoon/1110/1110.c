#include <stdio.h>

int main() {
  int n, tmp, ret;
  scanf("%d", &n);
  tmp = n;
  ret = 0;
  do {
    tmp = 10 * (tmp % 10) + (tmp / 10 + tmp % 10) % 10;
    ret ++;
  } while(n != tmp);
  printf("%d\n", ret);
  return 0;
}
