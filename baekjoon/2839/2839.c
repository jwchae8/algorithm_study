#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  if(n%5 == 0)
    printf("%d\n", n / 5);
  else if(n%5 == 1 && n >= 6)
    printf("%d\n", (n - 6) / 5 + 2);
  else if(n%5 == 2 && n >= 12)
    printf("%d\n", (n - 12) / 5 + 4);
  else if(n%5 == 3 && n >= 3)
    printf("%d\n", (n - 3) / 5 + 1);
  else if(n%5 == 4 && n >= 9)
    printf("%d\n", (n - 9) / 5 + 3);
  else
    printf("-1\n");
  return 0;
}
