#include <stdio.h>

int main() {
  char word[101];
  int i=0, len=0;
  scanf("%s", word);
  while(word[i] != 0) {
    len++;
    if(word[i] == 'c' && (word[i+1] == '=' || word[i+1] == '-')) {
      i += 2;
    } else if(word[i] == 'd' && word[i+1]!= 0) {
      if(word[i+1] == 'z' && word[i+2] == '=') {
        i += 3;
      } else if(word[i+1] == '-') {
        i += 2;
      } else {
        i += 1;
      }
    } else if((word[i] == 'l' || word[i] == 'n') && word[i+1] == 'j') {
      i += 2;
    } else if((word[i] == 's' || word[i] == 'z') && word[i+1] == '=') {
      i += 2;
    } else {
      i += 1;
    }
  }
  printf("%d\n", len);
  return 0;
}
