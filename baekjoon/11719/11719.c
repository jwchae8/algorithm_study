#include <stdio.h>

int main() {
  char *s = NULL;
  int size = 101;
  while(getline(&s, &size, stdin) != -1)
    printf("%s", s);
  return 0;
}
