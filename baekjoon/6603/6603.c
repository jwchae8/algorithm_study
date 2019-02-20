#include <stdio.h>

int set[13];
int choice[6];

void dfs(int k, int s, int depth) {
  int i;
  if(depth == 6) {
    for(i=0; i<6; i++)
      printf("%d ", choice[i]);
    printf("\n");
    return;
  }
  for(i=s; i<k-5+depth; i++) {
    choice[depth] = set[i];
    dfs(k, i+1, depth+1);
  }
}

int main() {
  int i, k;
  while(1) {
    scanf("%d", &k);
    if(k == 0)
      break;
    for(i=0; i<k; i++)
      scanf("%d", set+i);
    dfs(k, 0, 0);
    printf("\n");
  }
  return 0;
}
