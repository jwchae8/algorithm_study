#include <stdio.h>

int a[51];
int sorted_a[51];
int b[51];
int sorted_b[51];

void sort(int l, int r) {
  int i, j, k;
  if(l == r)
    return;
  sort(l, (l+r)/2);
  sort((l+r)/2+1 ,r);
  for(i=l, j=(l+r)/2+1, k=l; i<=(l+r)/2 || j<=r; ) {
    if(j > r || (i <= (l+r) / 2 && a[i] < a[j]))
      sorted_a[k++] = a[i++];
    else
      sorted_a[k++] = a[j++];
  }
  for(i=l, j=(l+r)/2+1, k=l; i<=(l+r)/2 || j<=r; ) {
    if(j > r || (i <= (l+r) / 2 && b[i] > b[j]))
      sorted_b[k++] = b[i++];
    else
      sorted_b[k++] = b[j++];
  }
  for(k=l; k<=r; k++) {
    a[k] = sorted_a[k];
    b[k] = sorted_b[k];
  }
}

int main() {
  int n, i, sum = 0;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", a+i);
  }
  for(i=0; i<n; i++) {
    scanf("%d", b+i);
  }
  sort(0, n-1);
  for(i=0; i<n; i++) {
    sum += a[i] * b[i];
  }
  printf("%d\n", sum);
  return 0;
}
