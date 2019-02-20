#include <stdio.h>

int main() {
  int i, n;
  unsigned long long int m, heights[1000000], ret = 0, diff, min=0, max=-1;
  scanf("%d %llu", &n, &m);
  for(i=0; i<n; i++) {
    scanf("%llu", heights+i);
    if(max < heights[i])
      max = heights[i];
    ret += heights[i];
  }
  ret /= n;
  while(1) {
    diff = 0;
    for(i=0; i<n; i++) {
      diff += heights[i] > ret ? heights[i] - ret : 0;
    }
    if(diff == m)
      break;
    else if(diff > m) {
      min = ret;
      if(ret == (min + max) / 2)
        break;
      else
        ret = (min + max) / 2;
    }
    else {
      max = ret;
      if(ret == (min + max) / 2) {
        ret++;
        break;
      }
      else
        ret = (min + max) / 2;
    }
  }
  printf("%llu\n", ret);
  return 0;
}
