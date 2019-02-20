#include <stdio.h>

int main() {
  unsigned long long int fib[91];
  int i, n;
  scanf("%d", &n);
  fib[0] = 0; fib[1] = 1;
  for(i=2; i<=n; i++)
    fib[i] = fib[i-1] + fib[i-2];
  printf("%llu\n", fib[n]);
  return 0;
}
