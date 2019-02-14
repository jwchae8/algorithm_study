#include <stdio.h>

int main() {
  char *grades = "FFFFFFDCBAA";
  int score;
  scanf("%d", &score);
  printf("%c\n", grades[score/10]);
  return 0;
}
