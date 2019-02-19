#include <stdio.h>
#include <string.h>

int main() {
  int i, j, k, t, n;
  char S[21];
  scanf("%d", &t);
  for(i=0; i<t; i++) {
    scanf("%d %s", &n, S);
    for(j=0; j<strlen(S); j++) {
      for(k=0; k<n; k++) {
        printf("%c", S[j]);
      }
    }
    printf("\n");
  }
  return 0;
}
