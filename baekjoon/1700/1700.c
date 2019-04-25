#include <stdio.h>

int ans, used[102], future[102];

int main() {
  int i, j, n, free, k, cnt, off;
  int sched[102];
  scanf("%d %d", &n, &k);
  free = n;
  for(i=0; i<k; i++) scanf("%d", sched+i);
  for(i=0; i<k; i++) {
    if(used[sched[i]]) continue;
    if(free>0) {
      free--; used[sched[i]]=1;
    } else {
      cnt = 0;
      for(j=i+1; j<k; j++) {
        if(used[sched[j]] && future[sched[j]] != i) {
          cnt++;
          future[sched[j]] = i;
          off = sched[j];
        }
      }
      if(cnt == n) {
        used[off] = 0;
        used[sched[i]] = 1;
      } else {
        for(j=0; j<i; j++) {
          if(used[sched[j]] && future[sched[j]] != i) {
            used[sched[j]] = 0;
            used[sched[i]] = 1;
            break;
          }
        }
      }
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
