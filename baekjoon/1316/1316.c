#include <stdio.h>
#include <string.h>

int main() {
  int i, j, n, ret=0;
  char word[101], cur;
  int count[26];
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%s", word);
    memset(count, 0, sizeof(int) * 26);
    cur = word[0];
    count[cur - 'a']++;
    for(j=1; word[j]!=0; j++) {
      if(word[j] != cur) {
        if(count[word[j] - 'a'] == 0) {
          cur = word[j];
          count[cur - 'a']++;
        }
        else {
          cur = 0;
          break;
        }
      }
    }
    if(cur)
      ret++;
  }
  printf("%d\n", ret);
  return 0;
}
