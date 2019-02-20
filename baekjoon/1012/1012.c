#include <stdio.h>
#include <string.h>

int map[50][50];
int visit[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int n, int m, int y, int x) {
  int i;
  visit[y][x] = 1;
  for(i=0; i<4; i++) {
    if(!(y+dy[i] >= 0 && y + dy[i] < n && x+dx[i] >= 0 && x+dx[i] < m))
      continue;
    if(map[y+dy[i]][x+dx[i]] && !visit[y+dy[i]][x+dx[i]])
      dfs(n, m, y+dy[i], x+dx[i]);
  }
}

int main() {
  int i, j, t;
  int m, n, k;
  int x, y;
  int ret;
  scanf("%d", &t);
  while(t-- > 0) {
    ret = 0;
    scanf("%d %d %d", &m, &n, &k);
    memset(map, 0, sizeof(int) * 50 * 50);
    memset(visit, 0, sizeof(int) * 50 * 50);
    for(i=0; i<k; i++) {
      scanf("%d %d", &x, &y);
      map[y][x] = 1;
    }
    for(i=0; i<n; i++) {
      for(j=0; j<m; j++) {
        if(map[i][j] && !visit[i][j]) {
          dfs(n, m, i, j);
          ret++;
        }
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}
