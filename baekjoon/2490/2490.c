#include <stdio.h>

int main() {
  int i, a, b, c, d;
  char yut[6] ="DCBAE";
  for(i=0; i<3; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%c\n", yut[a+b+c+d]);
  }
  return 0;
}
