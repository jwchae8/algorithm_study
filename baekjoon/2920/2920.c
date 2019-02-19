#include <stdio.h>

int main() {
  int ascending[8] = {1,2,3,4,5,6,7,8};
  int descending[8] = {8,7,6,5,4,3,2,1};
  int d = 0, a = 0, i, n;
  for(i=0; i<8; i++) {
    scanf("%d", &n);
    d += (descending[i] == n) ? 1 : 0;
    a += (ascending[i] == n) ? 1 : 0;
  }
  if(d == 8)
    printf("descending\n");
  else if(a == 8)
    printf("ascending\n");
  else
    printf("mixed\n");
  return 0;
}
