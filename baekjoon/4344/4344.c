#include <stdio.h>

int main() {
  int i, j, t, n, s[1000], over;
  float sum, avg;
  scanf("%d", &t);
  for(i=0; i<t; i++) {
    scanf("%d", &n);
    sum = 0;
    over = 0;
    for(j=0; j<n; j++) {
      scanf("%d", s+j);
      sum += s[j];
    }
    avg = sum / n;
    for(j=0; j<n; j++) {
      if(s[j] > avg)
        over++;
    }
    printf("%.3f%%\n", 100.0 *  over / n);
  }
  return 0;
}
