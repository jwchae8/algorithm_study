#include <stdio.h>

int main() {
  int i, n, max=-1;
  int arr[10] = {0};
  scanf("%d", &n);
  arr[0] += n == 0 ? 1 : 0;
  while(n) {
    arr[n%10]++;
    n /= 10;
  }
  arr[9] += arr[6];
  arr[9] = (arr[9] + 1) / 2;
  arr[6] = 0;
  for(i=0; i<10; i++) {
    if(arr[i] && max < arr[i])
      max = arr[i];
  }
  printf("%d\n", max);
  return 0;
}
