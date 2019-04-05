#include <stdio.h>

int main() {
  int i, j, pos, arr[5], sorted[5], sum = 0;
  for(i=0; i<5; i++) {
    scanf("%d", arr + i);
    sum += arr[i];
    pos = i;
    for(j=i-1; j>=0; j--) {
      if(sorted[j] < arr[i])
        pos--;
    }
    for(j=i; j>pos; j--) {
      sorted[j] = sorted[j-1];
    }
    sorted[pos] = arr[i];
  }
  printf("%d\n", sum / 5);
  printf("%d\n", sorted[2]);
}
