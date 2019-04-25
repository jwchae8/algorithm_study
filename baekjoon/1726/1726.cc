#include <cstdio>
#include <queue>

struct state {
  int x;
  int y;
  int dir;
  int cnt;
};

int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
bool board[101][101];
bool visit[101][101][5];

int main() {
  int i, j, k, n, m, x, y, dir;
  int e1, e2, e3;
  struct state cur;
  std::queue<struct state> q;
  std::scanf("%d %d", &n, &m);
  for(i=1;i<=n;i++) {
    for(j=1;j<=m;j++) {
      std::scanf("%d", &k);
      board[i][j] = k == 1;
    }
  }
  std::scanf("%d %d %d", &cur.x, &cur.y, &cur.dir);
  std::scanf("%d %d %d", &e1, &e2, &e3);
  cur.cnt=0;
  q.push(cur);
  while(!q.empty()) {
    cur = q.front(); q.pop();
    if(cur.x == e1 && cur.y == e2 && cur.dir == e3) {
      printf("%d\n", cur.cnt);
      break;
    }
    for(i=1; i<=3; i++) {
      x = cur.x+dx[cur.dir]*i; y = cur.y+dy[cur.dir]*i;
      if(!board[x][y] && !visit[x][y][cur.dir] && x >= 1 && x <= n && y >= 1 && y <= m) {
        visit[x][y][cur.dir] = true;
        struct state next = {x, y, cur.dir, cur.cnt+1};
        q.push(next);
      }
      if(board[x][y])
        break;
    }
    dir = cur.dir < 3 ? 3 : 1;
    if(!visit[cur.x][cur.y][dir]) {
      visit[cur.x][cur.y][dir] = true;
      struct state next = {cur.x, cur.y, dir, cur.cnt+1};
      q.push(next);
    }
    dir = cur.dir < 3 ? 4 : 2;
    if(!visit[cur.x][cur.y][dir]) {
      visit[cur.x][cur.y][dir] = true;
      struct state next = {cur.x, cur.y, dir, cur.cnt+1};
      q.push(next);
    }
  }
  return 0;
}
