#include <stdio.h>

int main() {
  char s[101];
  while(gets(s) != NULL && s[0] != 0)
    printf("%s\n", s);
  return 0;
}
