#include <stdio.h>

int main() {
  int i, n, m, arr[300], cnt[300], hi, lo, mid, prev, group, sum;
  scanf("%d", &n);
  scanf("%d", &m);
  for(i=0; i<n; i++) {
    scanf("%d", arr+i);
  }
  hi = 100 * n; lo = 0;
  while(hi >= lo) {
    mid = (hi + lo) / 2;
    group = 0; sum = 0; prev = 0;
    for(i=0; i<n; i++) {
      sum += arr[i];
      if(sum > mid) {
        if(i - prev) {
          cnt[group++] = i - prev;
        } else {
          group = m+1;
          break;
        }
        sum = 0;
        prev = i--;
      }
    }
    cnt[group++] = i - prev;
    if(group > m) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  printf("%d\n", lo);
  group = 0; sum = 0; prev = 0;
  for(i=0; i<n; i++) {
    if(n - prev == m)
      break;
    sum += arr[i];
    if(sum > lo) {
      printf("%d ", i - prev);
      sum = 0;
      prev = i--;
      m--;
    }
  }
  if(n - prev == m) {
    for(i=0; i<m; i++) {
      printf("1 ");
    }
  } else {
    printf("%d", i - prev);
  }
  return 0;
}
