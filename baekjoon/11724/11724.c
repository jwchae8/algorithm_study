#include <stdio.h>

int graph[1001][1001];
int visit[1001];

void dfs(int u, int n) {
  int i = n+1;
  visit[u] = 1;
  while(i-- > 0){
    if(graph[u][i] && !visit[i])
      dfs(i, n);
  }
}
int main() {
  int i, n, m, u, v, ret = 0;
  scanf("%d %d", &n, &m);
  for(i=0; i<m; i++) {
    scanf("%d %d", &u, &v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
  for(i=1; i<=n; i++) {
    if(!visit[i]) {
      dfs(i, n);
      ret++;
    }
  }
  printf("%d\n", ret);
  return 0;
}
