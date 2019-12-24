#include <stdio.h>

int main() {
  int row_cnt[5] = {5, 5, 5, 5, 5};
  int col_cnt[5] = {5, 5, 5, 5, 5};
  int pos[26];
  int diag = 5, undiag = 5;
  int i, j;
  int bingo = 0;
  for(i=0; i<25; i++) {
    scanf("%d", &j);
    pos[j] = i;
  }
  for(i=1; i<=25; i++) {
    scanf("%d", &j);
    if(!(--row_cnt[pos[j]/5]))bingo++;
    if(!(--col_cnt[pos[j]%5]))bingo++;
    if(pos[j]/5==pos[j]%5) {
      if(!(--diag))bingo++;
    }
    if(pos[j]/5+pos[j]%5==4) {
      if(!(--undiag))bingo++;
    }
    if(bingo>2)break;
  }
  printf("%d\n", i);
  return 0;
}
