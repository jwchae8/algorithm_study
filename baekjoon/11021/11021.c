#include <stdio.h>

int main() {
  int t, a, b, cnt = 0;
  scanf("%d", &t);
  while(cnt++ < t) {
    scanf("%d %d", &a, &b);
    printf("Case #%d: %d\n", cnt, a+b);
  }
  return 0;
}
