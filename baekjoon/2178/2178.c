#include <stdio.h>

int maze[100][100];
int visited[100][100];
int queue[10000];
int front, rear;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void push(int n) {
  queue[rear++] = n;
}

int pop() {
  return queue[front++];
}

int main() {
  int i, j, N, M, n, m, cur;
  scanf("%d %d", &N, &M);
  for(i=0; i<N; i++) {
    for(j=0; j<M; j++) {
      char tmp;
      scanf(" %c", &tmp);
      maze[i][j] = tmp - '0';
    }
  }
  push(0);
  visited[0][0] = 1;
  do {
    cur = pop();
    n = cur / M;
    m = cur % M;
    for(i=0; i<4; i++) {
      if(!(n + dy[i] >= 0 && n + dy[i] < N && m + dx[i] >= 0 && m + dx[i] < M))
        continue;
      if(!visited[n + dy[i]][m + dx[i]] && maze[n + dy[i]][m + dx[i]]) {
        push((n + dy[i]) * M + (m + dx[i]));
        visited[n + dy[i]][m+dx[i]] = visited[n][m] + 1;
      }
    }
  } while(front != rear);
  printf("%d\n", visited[N-1][M-1]);
  return 0;
}
