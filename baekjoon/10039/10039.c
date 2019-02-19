#include <stdio.h>

int main() {
  int i, grade, sum = 0;
  for(i=0; i<5; i++) {
    scanf("%d", &grade);
    grade = grade > 40 ? grade : 40;
    sum += grade;
  }
  printf("%d\n", sum / 5);
  return 0;
}
