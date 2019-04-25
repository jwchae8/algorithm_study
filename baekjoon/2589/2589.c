#include <stdio.h>

int queue[2500];
char island[52][52];
int head, tail;
int n, m, ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void push(int n) {
  queue[head++] = n;
}

int pop() {
  return queue[tail++];
}

void solve() {
  int i, j, p, px, py;
  int local_visited[52][52];
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      local_visited[i][j] = 0;
    }
  }
  while(head > tail) {
    p = pop();
    for(i=0; i<4; i++) {
      px = p / m + dx[i]; py = p % m + dy[i];
      if(px < 0 || px >= n || py < 0 || py >= m) {
        continue;
      }
      if(island[px][py] == 'L' && !local_visited[px][py]) {
        push(px * m + py);
        local_visited[px][py] = local_visited[p/m][p%m] + 1;
        if(local_visited[px][py] > ans)
          ans = local_visited[px][py];
      }
    }
  }
}

int is_middle(int x, int y) {
  int i, neighbor[4], px, py;
  for(i=0; i<4; i++) {
    px = x+dx[i]; py = y+dy[i];
    neighbor[i] = !(px < 0 || px >= n || py < 0 || py >=m) && island[px][py] == 'L';
  }
  return (neighbor[0] && neighbor[1] && !neighbor[2] && !neighbor[3]) || (!neighbor[0] && !neighbor[1] && neighbor[2] && neighbor[3]);
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      scanf(" %c", &island[i][j]);
    }
  }
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      if(island[i][j] == 'L' && !is_middle(i, j)) {
        head = 0; tail = 0;
        push(i * m + j);
        solve();
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
