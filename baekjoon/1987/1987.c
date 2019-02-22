#include <stdio.h>

int r, c;
char board[21][21];
int history[27];
int cnt, max_cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
  int i, x2, y2;
  cnt++;
  if(cnt > max_cnt)
    max_cnt = cnt;
  for(i=0; i<4; i++) {
    x2 = x + dx[i]; y2 = y + dy[i];
    if(x2 >= 0 && x2 < r && y2 >= 0 && y2 < c) {
      if(!history[board[x2][y2] - 'A']) {
        history[board[x2][y2] - 'A'] = 1;
        dfs(x2, y2);
        history[board[x2][y2] - 'A'] = 0;
      }
    }
  }
  cnt--;
}

int main() {
  int i, j;
  scanf("%d %d", &r, &c);
  for(i=0; i<r; i++) {
    for(j=0; j<c; j++) {
      scanf(" %c", &board[i][j]);
    }
  }
  history[board[0][0] - 'A'] = 1;
  dfs(0, 0);
  printf("%d\n", max_cnt);
  return 0;
}
