#include <stdio.h>

int graph[1001][1001];
int visited[1001];
int queue[1001];
int front, rear;

void push(int n) {
  queue[rear++] = n;
}

int pop() {
  return queue[front++];
}

int empty() {
  return rear == front;
}

void bfs(int n, int cur) {
  int i;
  push(cur);
  do {
    cur = pop();
    printf("%d ", cur);
    for(i=1; i<=n; i++) {
      if(graph[cur][i] && !visited[i]) {
        push(i);
        visited[i] = 1;
      }
    }
  } while(!empty());
}

void dfs(int n, int cur) {
  int i;
  printf("%d ", cur);
  for(i=1; i<=n; i++) {
    if(graph[cur][i] && !visited[i]) {
      visited[i] = 1;
      dfs(n, i);
    }
  }
}

int main() {
  int i, v1, v2, n, m, start;
  scanf("%d %d %d", &n, &m, &start);
  for(i=0; i<m; i++) {
    scanf("%d %d", &v1, &v2);
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
  }
  visited[start] = 1;
  dfs(n, start);
  for(i=1; i<=n; i++)
    visited[i] = 0;
  printf("\n");
  visited[start] = 1;
  bfs(n, start);
  return 0;
}
