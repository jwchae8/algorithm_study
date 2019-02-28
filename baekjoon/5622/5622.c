#include <stdio.h>

int main() {
  int i = 0, sum = 0, time[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
  char word[16];
  scanf("%s", word);
  while(word[i] != 0) 
    sum += time[(word[i++] - 'A')];
  printf("%d\n", sum);
  return 0;
}
