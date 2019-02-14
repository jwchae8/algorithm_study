#include <stdio.h>

int main() {
  int i = 0;
  char s[101];
  scanf("%s", s);
  while(s[i] != 0) {
    printf("%c", s[i]);
    i++;
    if(i % 10 == 0 && i > 0)
      printf("\n");
  }
  return 0;
}
