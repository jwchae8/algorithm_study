#include <stdio.h>
#include <string.h>

int main() {
  int i, j, n, arr[1001], ret = 0;
  memset(arr, 0, sizeof(int) * 1001);
  arr[1] = 1;
  for(i=2; i<=1000; i++) {
    if(arr[i])
      continue;
    for(j=2; i*j<=1000; j++) {
      arr[i*j] = 1;
    }
  }
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &j);
    if(!arr[j])
      ret += 1;
  }
  printf("%d\n", ret);
  return 0;
}
