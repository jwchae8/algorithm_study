#include <stdio.h>

int main() {
  int i, n, s, max = 0;
  float sum = 0;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &s);
    if(max < s)
      max = s;
    sum += s;
  }
  printf("%f\n", sum / n * 100 / max);
  return 0;
}
