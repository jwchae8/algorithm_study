#include <stdio.h>

int prime[10001];

int main() {
  int i, j, m, n, min=99999, sum=0;
  scanf("%d %d", &m, &n);
  prime[1] = 1;
  for(i=2; i<=5000; i++) {
    if(prime[i])continue;
    for(j=2; i*j<=10000; j++) {
      prime[i*j] = 1;
    }
  }
  for(i=m; i<=n; i++) {
    if(!prime[i]) {
      if(min==99999) min=i;
      sum += i;
    }
  }
  if(sum)
    printf("%d\n%d\n", sum, min);
  else
    printf("-1\n");
  return 0;
}
