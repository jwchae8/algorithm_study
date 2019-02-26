#include <stdio.h>

int n, count;
int graph[101][101];
int visit[101];

void dfs(int c) {
  int i;
  visit[c] = 1;
  count++;
  for(i=1; i<=n; i++) {
    if(graph[c][i] && !visit[i])
      dfs(i);
  }
}
int main() {
  int e, u, v;
  scanf("%d", &n);
  scanf("%d", &e);
  while(e-- > 0) {
    scanf("%d %d", &u, &v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  dfs(1);
  printf("%d\n", count-1);
  return 0;
}
