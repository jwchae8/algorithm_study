#include <stdio.h>
#include <string.h>

int main() {
  int i, j, t, cur, ret;
  char seq[100];
  scanf("%d", &t);
  for(i=0; i<t; i++) {
    ret = 0;
    cur = 1;
    scanf("%s", seq);
    for(j=0; j<strlen(seq); j++) {
      if(seq[j] == 'O')
        ret += cur++;
      else
        cur = 1;
    }
    printf("%d\n", ret);
  }
  return 0;
}
