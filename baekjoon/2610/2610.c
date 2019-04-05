#include <stdio.h>

#define INF 1000000
int dist[101][101];
int visited[101];
int arr[101];
int sorted_arr[101];

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
  int i, j, k, n, m, u, v, min, max, min_index, cnt = 0;
  scanf("%d", &n);
  scanf("%d", &m);
  for(i=1; i<=n; i++) {
    for(j=1; j<=n; j++) {
      dist[i][j] = INF;
    }
  }
  for(i=0; i<m; i++) {
    scanf("%d %d", &u, &v);
    dist[u][v] = 1;
    dist[v][u] = 1;
  }
  for(i=1; i<=n; i++) {
    dist[i][i] = 0;
  }
  for(k=1; k<=n; k++) {
    for(i=1; i<=n-1; i++) {
      for(j=i+1; j<=n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          dist[j][i] = dist[i][j];
        }
      }
    }
  }
  for(i=1; i<=n; i++) {
    if(visited[i])
      continue;
    visited[i] = 1;
    min = INF; min_index = i;
    for(j=i; j<=n; j++) {
      if(dist[i][j] < INF) {
        max = -1;
        for(k=1; k<=n; k++) {
          if(dist[j][k] < INF && max < dist[j][k]) {
            max = dist[j][k];
          }
        }
        if(max > 0 && min > max) {
          min = max;
          min_index = j;
        }
        visited[j] = 1;
      }
    }
    arr[cnt++] = min_index;
  }
  printf("%d\n", cnt);
  sort(0, cnt-1);
  for(i=0; i<cnt; i++)
    printf("%d\n", arr[i]);
  return 0;
}
