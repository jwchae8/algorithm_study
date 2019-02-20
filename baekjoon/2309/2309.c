#include <stdio.h>

int arr[9];
int sorted_arr[9];

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
  int i, j, sum = 0, vic1, vic2;
  for(i=0; i<9; i++) {
    scanf("%d", arr+i);
    sum += arr[i];
  }
  sort(0, 8);
  sum -= 100;
  for(i=0; i<8; i++) {
    for(j=i+1; j<9; j++) {
      if(arr[i] + arr[j] == sum) {
        vic1 = i;
        vic2 = j;
        break;
      }
    }
    if(j != 9)
      break;
  }
  for(i=0; i<9; i++) {
    if(i != vic1 && i != vic2) {
      printf("%d\n", arr[i]);
    }
  }
  return 0;
}
