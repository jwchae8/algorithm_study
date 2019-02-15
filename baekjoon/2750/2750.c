#include <stdio.h>

int arr[1000];
int sorted_arr[1000];

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
  int i, n;
  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);
  sort(0, n-1);
  for(i=0; i<n; i++)
    printf("%d\n", arr[i]);
  return 0;
}
