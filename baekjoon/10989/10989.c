#include <stdio.h>

int arr[10001];

int main() {
  int i, j, n, num;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &num);
    arr[num]++;
  }
  for(i=0; i<=10000; i++) {
    for(j=0; j<arr[i]; j++) {
      printf("%d\n", i);
    }
  }
  return 0;
}
