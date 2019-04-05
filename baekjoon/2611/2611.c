#include <stdio.h>

int dist[1001][1001];
int next[1001][1001];
int dp[1001];
int path[1001];
int cnt[1001];

int race(int p) {
  int i, d, max = -1;
  if(!dp[p] && p != 1) {
    for(i=0; i < cnt[p]; i++) {
      d = race(next[p][i]) + dist[p][i];
      if(d > max) {
        max = d;
        path[p] = next[p][i];
      }
    }
    dp[p] = max;
  }
  return dp[p];
}

int main() {
  int d, i, n, m, p, q, r, max = -1, first_step = 0;
  scanf("%d", &n);
  scanf("%d", &m);
  for(i=0; i<m; i++) {
    scanf("%d %d %d", &p, &q, &r);
    next[p][cnt[p]] = q;
    dist[p][cnt[p]++] = r;
  }
  for(i=0; i<cnt[1]; i++) {
    d = race(next[1][i]) + dist[1][i];
    if(d > max) {
      max = d;
      first_step = next[1][i];
    }
  }
  printf("%d\n1", max);
  i = first_step;
  while(i) {
    printf(" %d", i);
    i = path[i];
  }
  return 0;
}
