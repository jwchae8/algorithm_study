#include <stdio.h>

int main() {
  char *s = NULL;
  size_t size = 1000001;
  int words = 0, space = 1;
  getline(&s, &size, stdin);
  while(*s) {
    if(*s == ' ' && !space)
      space = 1;
    if(*s != ' ' && *s != '\n' && space) {
      words += 1;
      space = 0;
    }
    s++;
  }
  printf("%d\n", words);
  return 0;
}
