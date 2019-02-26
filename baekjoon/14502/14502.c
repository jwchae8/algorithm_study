#include <stdio.h>

int lab[10][10];
int n, m;

int queue[1000];
int front, rear;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void push(int n) {
  queue[front++ % 1000] = n;
}

int pop() {
  return queue[rear++ % 1000];
}

int main() {
  int i, j, k, u, v, p, px, py, nx, ny, safe, max_safe = -1;
  scanf("%d %d", &n, &m);
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      scanf("%d", &lab[i][j]);
    }
  }
  for(i=0; i<n*m; i++) {
    if(!lab[i/m][i%m]) {
      lab[i/m][i%m] = 1;
      for(j=i+1; j<n*m; j++) {
        if(!lab[j/m][j%m]) {
          lab[j/m][j%m] = 1;
          for(k=j+1; k<n*m; k++) {
            if(!lab[k/m][k%m]) {
              lab[k/m][k%m] = 1;
              for(u=0; u<n; u++) {
                for(v=0; v<m; v++) {
                  if(lab[u][v] == 2)
                    push(u*m+v);
                }
              }
              while(front > rear) {
                p = pop();
                px = p % m; py = p / m;
                if(!lab[py][px])
                  lab[py][px] = 3;
                for(u=0; u<4; u++) {
                  nx = px + dx[u]; ny = py + dy[u];
                  if(nx >= 0 && nx < m && ny >= 0 && ny < n && !lab[ny][nx])
                    push(ny*m+nx);
                }
              }
              safe = 0;
              for(u=0; u<n; u++) {
                for(v=0; v<m; v++) {
                  if(lab[u][v] == 0)
                    safe++;
                  else if(lab[u][v] == 3)
                    lab[u][v] = 0;
                }
              }
              if(safe > max_safe)
                max_safe = safe;
              lab[k/m][k%m] = 0;
            }
          }
          lab[j/m][j%m] = 0;
        }
      }
      lab[i/m][i%m] = 0;
    }
  }
  printf("%d\n", max_safe);
  return 0;
}
