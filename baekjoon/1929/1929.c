#include <stdio.h>

int num[1000001];

int main() {
  int i, j, n, m;
  scanf("%d %d", &n, &m);
  num[1] = 1;
  for(i=2; i * i <= m; i++) {
    for(j=2; i * j <= m; j++) {
      num[i*j] = 1;
    }
  }
  for(i=n; i<=m; i++) {
    if(!num[i])
      printf("%d\n", i);
  }
  return 0;
}
