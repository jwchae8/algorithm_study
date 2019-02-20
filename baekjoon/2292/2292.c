#include <stdio.h>

int main() {
  int i = 0, n, cur = 1;
  scanf("%d", &n);
  while(1) {
    cur += i * 6;
    i++;
    if(cur >= n)
      break;
  }
  printf("%d\n", i);
  return 0;
}
