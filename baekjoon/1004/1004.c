#include <stdio.h>

int is_in(int cx, int cy, int cr, int px, int py) {
  int dist = (px - cx) * (px - cx) + (py - cy) * (py - cy);
  return cr * cr > dist;
}

int main() {
  int i, t;
  scanf("%d", &t);
  for(i=0; i<t; i++) {
    int ret = 0;
    int sx, sy, ex, ey;
    int j, ps;
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    scanf("%d", &ps);
    for(j=0; j<ps; j++) {
      int cx, cy, cr;
      scanf("%d %d %d", &cx, &cy, &cr);
      if(is_in(cx, cy, cr, sx, sy) != is_in(cx, cy, cr, ex, ey)) {
        ret += 1;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}
