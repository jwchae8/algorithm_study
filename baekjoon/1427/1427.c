#include <stdio.h>

char arr[12];
char sorted_arr[12];

void sort(int l, int r) {
  int i, j, k;
  if(l == r)
    return;
  sort(l, (l+r)/2);
  sort((l+r)/2+1 ,r);
  for(i=l, j=(l+r)/2+1, k=l; i<=(l+r)/2 || j<=r; ) {
    if(j > r || (i <= (l+r) / 2 && arr[i] < arr[j]))
      sorted_arr[k++] = arr[i++];
    else
      sorted_arr[k++] = arr[j++];
  }
  for(k=l; k<=r; k++)
    arr[k] = sorted_arr[k];
}

int main() {
  int i = 0, j, n;
  scanf("%d", &n);
  while(n) {
    arr[i++] = (n % 10) + '0';
    n /= 10;
  }
  sort(0, i-1);
  for(j=i-1; j>=0; j--)
    printf("%c", arr[j]);
  return 0;
}
