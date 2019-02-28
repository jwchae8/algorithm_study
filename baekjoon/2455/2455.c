#include <stdio.h>

int main() {
  int i, x, y, cur=0, max = -1;
  for(i=0; i<4; i++) {
    scanf("%d %d", &x, &y);
    cur += y - x;
    if(cur > max)
      max = cur;
  }
  printf("%d\n", max);
  return 0;
}
