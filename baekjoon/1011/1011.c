#include <stdio.h>

int main() {
  int t, u, v;
  unsigned long long int diff, step;
  scanf("%d", &t);
  while(t-- > 0) {
    scanf("%d %d", &u, &v);
    diff = v - u;
    step = 0;
    while(step * step < diff) step++;
    if(diff <= step * (step - 1))
      printf("%llu\n", step * 2 - 2);
    else
      printf("%llu\n", step * 2 - 1);
  }
  return 0;
}
