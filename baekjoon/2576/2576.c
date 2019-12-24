#include <stdio.h>

int main() {
  int i, num[7], sum=0, min=100;
  for(i=0; i<7; i++) scanf("%d", num+i);
  for(i=0; i<7; i++) {
    if(num[i] % 2) {
      sum += num[i];
      if(min > num[i]) min = num[i];
    }
  }
  if(sum == 0) {
    printf("-1\n");
  } else {
    printf("%d\n%d\n", sum, min);
  }
  return 0;
}
