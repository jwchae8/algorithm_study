#include <stdio.h>

int main() {
  int i, n, ret = 99;
  scanf("%d", &n);
  if(n < 100) {
    printf("%d\n", n);
  } else {
    for(i=100; i<=n && i < 1000; i++) {
      int a = i % 10, b = (i / 10) % 10, c = (i / 100) % 10;
      if(a - b == b - c)
        ret++;
    }
    printf("%d\n", ret);
  }
  return 0;
}
