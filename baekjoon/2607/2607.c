#include <stdio.h>
#include <string.h>

int main() {
  int i, w, sim = 0, more, less;
  char fword[11], word[11];
  int falpha[26];
  int alpha[26];
  scanf("%d", &w);
  scanf("%s", fword);
  memset(falpha, 0, sizeof(int)*26);
  for(i=0; fword[i] != 0; i++) {
    falpha[fword[i] - 'A']++;
  }
  while(--w > 0) {
    memset(alpha, 0, sizeof(int) * 26);
    more = 0; less = 0;
    scanf("%s", word);
    for(i=0; word[i] != 0; i++) {
      alpha[word[i] - 'A']++;
    }
    for(i=0; i<26; i++) {
      if(falpha[i] - alpha[i] > 1 || falpha[i] - alpha[i] < -1) {
        more = 999;
        break;
      }
      if(falpha[i] - alpha[i] == 1) {
        more++;
      }
      if(falpha[i] - alpha[i] == -1) {
        less++;
      }
    }
    if(more <= 1 && less <= 1) sim++;
  }
  printf("%d\n", sim);
  return 0;
}
