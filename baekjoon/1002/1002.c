#include <stdio.h>

int main() {
  int i, t;
  scanf("%d", &t);
  for(i=0; i<t; i++) {
    int dist, rad_sum, rad_diff;
    int x1, y1, r1, x2, y2, r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    rad_sum = (r1 + r2) * (r1 + r2);
    rad_diff = (r1 - r2) * (r1 - r2);
    if(!dist) {
      if(r1 == r2)
        printf("-1\n");
      else
        printf("0\n");
    }
    else if(dist > rad_sum || dist < rad_diff) {
      printf("0\n");
    }
    else if(dist == rad_sum || dist == rad_diff) {
      printf("1\n");
    }
    else {
      printf("2\n");
    }
  }
  return 0;
}
