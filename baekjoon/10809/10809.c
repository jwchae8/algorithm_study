#include <stdio.h>
#include <string.h>

int main() {
  int i, arr[26];
  char str[101];
  scanf("%s", str);
  memset(arr, -1, sizeof(int) * 26);
  for(i=0; i < strlen(str); i++) {
    if(arr[str[i] - 'a'] == -1)
      arr[str[i] - 'a'] = i;
  }
  for(i=0; i < 26; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
