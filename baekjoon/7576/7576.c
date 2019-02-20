#include <stdio.h>

int queue[1000000];
int front, rear;

int tomatoes[1000][1000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void push(int n) {
  queue[front++] = n;
}

int pop() {
  return queue[rear++];
}

int main() {
  int i, j, k, n, m, cur, zero = 0, days = 0;
  scanf("%d %d", &m, &n);
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      scanf("%d", &tomatoes[i][j]);
      if(tomatoes[i][j] == 0)
        zero++;
    }
  }
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      if(tomatoes[i][j] == 1) {
        for(k=0; k<4; k++) {
          if(i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m) {
            if(tomatoes[i+dy[k]][j+dx[k]] == 0) {
              push((i+dy[k]) * m + j+dx[k]);
              tomatoes[i+dy[k]][j+dx[k]] = 2;
              zero--;
            }
          }
        }
      }
    }
  }
  while(front != rear) {
    cur = pop();
    i = cur / m;
    j = cur % m;
    if(days < tomatoes[i][j] - 1)
      days = tomatoes[i][j] - 1;
    for(k=0; k<4; k++) {
      if(i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m) {
        if(tomatoes[i+dy[k]][j+dx[k]] == 0) {
          push((i+dy[k]) * m + j+dx[k]);
          tomatoes[i+dy[k]][j+dx[k]] = tomatoes[i][j] + 1;
          zero--;
        }
      }
    }
  }
  printf("%d\n", zero ? -1 : days);
  return 0;
}
