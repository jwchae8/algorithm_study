#include <stdio.h>

typedef struct node {
  int v;
  int d;
} node_t;

int graph[101][101];
node_t queue[101];
int visit[101];
int past[101];
int head, tail;

void push(node_t n) {
  queue[tail].v = n.v;
  queue[tail++].d = n.d;
}

node_t pop() {
  return queue[head++];
}

int gcd(int x, int y) {
  while(x > 0 && y > 0) {
    if(x > y) {
      x %= y;
    } else {
      y %= x;
    }
  }
  return x > 0 ? x : y;
}

int main() {
  int i, j, k, g, n, m, A, B, x[101] = {0}, y[101] = {0}, ans[101];
  int maxstart, minstart, maxstep, minstep;
  node_t src;
  scanf("%d %d", &n, &m);
  for(i=1; i<=m; i++) {
    scanf("%d %d", x+i, y+i);
    for(j=1; j<i; j++) {
      g = gcd(y[i], y[j]);
      if((x[i] - x[j]) % g){
        continue;
      } else {
        maxstart = x[i] > x[j] ? x[i] : x[j];
        minstart = x[i] < x[j] ? x[i] : x[j];
        maxstep = x[i] > x[j] ? y[i] : y[j];
        minstep = x[i] < x[j] ? y[i] : y[j];
        for(k=maxstart; k % minstep != minstart % minstep; k += maxstep);
        if(k <= n) { 
          graph[i][j] = 1;
          graph[j][i] = 1;
        }
      }
    }
  }
  scanf("%d %d", &A, &B);
  for(i=1; i<=m; i++) {
    if(x[i] <= A && x[i] % y[i] == A % y[i]) {
      visit[i] = 1;
      src.v = i; src.d = 1;
      push(src);
    }
  }
  j=0;
  while(head < tail) {
    node_t u = pop();
    if(x[u.v] <= B && x[u.v] % y[u.v] == B % y[u.v]) {
      printf("%d\n", u.d);
      i = u.v;
      while(i) {
        ans[j++] = i;
        i = past[i];
      }
      for(i=j-1; i>=0; i--) printf("%d\n", ans[i]);
      break;
    }
    for(i=1; i<=m; i++) {
      if(graph[i][u.v] && !visit[i]) {
        visit[i] = 1;
        past[i] = u.v;
        src.v = i; src.d = u.d+1;
        push(src);
      }
    }
  }
  if(!j)
    printf("-1\n");
  return 0;
}
