#include <stdio.h>

int main() {
  int a, b;
  char *line = NULL;
  size_t size;
  while(getline(&line, &size, stdin) != -1) {
    sscanf(line, "%d %d", &a, &b);
    printf("%d\n", a + b);
  }
  return 0;
}
