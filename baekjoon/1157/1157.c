#include <stdio.h>
#include <string.h>

int main() {
  int counts[27];
  int i, max_index = 1, max = -1, rep = 0;
  char word[1000001];
  scanf("%s", word);
  memset(counts, 0, sizeof(int) * 27);
  for(i=0; word[i]!=0; i++) {
    counts[word[i]%32] += 1;
  }
  for(i=1; i<=26; i++) {
    if(max < counts[i]) {
      max_index = i;
      max = counts[i];
      rep = 0;
    } else if(max == counts[i]) {
      rep++;
    }
  }
  printf("%c\n", rep == 0 ? 64 + max_index : '?');
  return 0;
}
