#include <stdio.h>

int C[1001][1001];
int begin[1001][1001];


int main() {
  int i, j, x, y, maxl = -1;
  int start, blankx, blanky, use;
  int cur;
  int xe, ye;
  char xs[1002], ys[1002];
  scanf("%d", &x);
  scanf("%s", xs+1);
  scanf("%d", &y);
  scanf("%s", ys+1);
  for(i=1; i<=x; i++) {
    for(j=1; j<=y; j++) {
      cur = xs[i] == ys[j] ? 3 : -2;
      begin[i][j] = i*(y+1) + j;
      if(cur < C[i-1][j] - 2) {
        cur = C[i-1][j] - 2;
        begin[i][j] = begin[i-1][j];
      }
      if(cur < C[i][j-1] - 2) {
        cur = C[i][j-1] - 2;
        begin[i][j] = begin[i][j-1];
      }
      if(cur < C[i-1][j-1] + (xs[i] == ys[j] ? 3 : -2)) {
        cur = C[i-1][j-1] + (xs[i] == ys[j] ? 3 : -2);
        begin[i][j] = begin[i-1][j-1];
      }
      C[i][j] = cur;
      if(C[i][j] > maxl) {
        maxl = C[i][j];
        xe = i;
        ye = j;
      }
    }
  }
  printf("%d\n", maxl);
  for(i=begin[xe][ye] / (y+1); i<=xe; i++)
    printf("%c", xs[i]);
  printf("\n");
  for(i=begin[xe][ye] % (y+1); i<=ye; i++)
    printf("%c", ys[i]);
  return 0;
}
