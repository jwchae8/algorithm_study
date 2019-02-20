#include <stdio.h>

int arr[500];
int sorted_arr[500];

int map[25][25];
int visit[25][25];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y, int n) {
  int i, ret = 1;
  visit[x][y] = 1;
  for(i=0; i<4; i++) {
    if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n) {
      if(map[x+dx[i]][y+dy[i]] && !visit[x+dx[i]][y+dy[i]])
        ret += dfs(x+dx[i], y+dy[i], n);
    }
  }
  return ret;
}

void sort(int l, int r) {
  int i, j, k;
  if(l == r)
    return;
  sort(l, (l+r)/2);
  sort((l+r)/2+1 ,r);
  for(i=l, j=(l+r)/2+1, k=l; i<=(l+r)/2 || j<=r; ) {
    if(j > r || (i <= (l+r) / 2 && arr[i] < arr[j]))
      sorted_arr[k++] = arr[i++];
    else
      sorted_arr[k++] = arr[j++];
  }
  for(k=l; k<=r; k++)
    arr[k] = sorted_arr[k];
}

int main() {
  int i, j, n, ret = 0;
  char tmp;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      scanf(" %c", &tmp);
      map[i][j] = tmp - '0';
    }
  }
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      if(map[i][j] && !visit[i][j]) {
        arr[ret++] = dfs(i, j, n);
      }
    }
  }
  sort(0, ret-1);
  printf("%d\n", ret);
  for(i=0; i<ret; i++)
    printf("%d\n", arr[i]);
  return 0;
}
