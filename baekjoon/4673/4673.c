#include <stdio.h>
#include <string.h>

int d(int n) {
  int ret = n;
  while(n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main() {
  int i, j, arr[10001];
  memset(arr, 0, sizeof(int) * 10001);
  for(i = 1; i <= 10000; i++) {
    if(arr[i])
      continue;
    j = i;
    while((j = d(j)) <= 10000) {
      arr[j] = 1;
    }
  }
  for(i = 1; i <= 10000; i++) {
    if(!arr[i])
      printf("%d\n", i);
  }
  return 0;
}
