#include <stdio.h>
#include <string.h>

char arr[20000][51];
char sorted_arr[20000][51];

int cmp(const char *a, const char *b) {
  int x = 0;
  while(a[x] != 0 && b[x] != 0) {
    x++;
  }
  if(a[x] == 0 && b[x] == 0)
    return strcmp(a, b);
  else if(a[x] == 0 && b[x] != 0)
    return -1;
  else
    return 1;
}
void sort(int l, int r) {
  int i, j, k;
  if(l == r)
    return;
  sort(l, (l+r)/2);
  sort((l+r)/2+1 ,r);
  for(i=l, j=(l+r)/2+1, k=l; i<=(l+r)/2 || j<=r; ) {
    if(j > r || (i <= (l+r) / 2 && cmp(arr[i], arr[j]) < 0))
      strcpy(sorted_arr[k++],arr[i++]);
    else
      strcpy(sorted_arr[k++],arr[j++]);
  }
  for(k=l; k<=r; k++)
    strcpy(arr[k],sorted_arr[k]);
}

int main() {
  int i, n;
  char word[51] = "";
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%s", arr[i]);
  }
  sort(0, n-1);
  for(i=0; i<n; i++) {
    if(strcmp(word, arr[i])) {
      printf("%s\n", arr[i]);
      strcpy(word, arr[i]);
    }
  }
  return 0;
}
