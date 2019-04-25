#include <stdio.h>
#include <stdlib.h>

long long int s1[1000], e1[1000], s2[1000], e2[1000];
long long int arr[4000002], sorted_arr[4000002], cnt;


int sign(int x) {
  return x > 0 ? 1 : -1;
}

void sort(int l, int r) {
  int i, j, k;
  if(l == r)
    return;
  sort(l, (l+r)/2);
  sort((l+r)/2+1 ,r);
  for(i=l, j=(l+r)/2+1, k=l; i<=(l+r)/2 || j<=r; ) {
    if(j > r || (i <= (l+r) / 2 && llabs(arr[i]) < llabs(arr[j])))
      sorted_arr[k++] = arr[i++];
    else
      sorted_arr[k++] = arr[j++];
  }
  for(k=l; k<=r; k++)
    arr[k] = sorted_arr[k];
}

int main() {
  int i, j, n, m, max=0, ans=0, acc=0, acc2=0;
  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%lld %lld", s1+i, e1+i);
  scanf("%d", &m);
  for(i=0; i<m; i++) scanf("%lld %lld", s2+i, e2+i);
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      arr[cnt++] = s1[i] + s2[j];
      arr[cnt++] = e1[i] + e2[j] + 2;
      arr[cnt++] = -(s1[i] + e2[j] + 1);
      arr[cnt++] = -(s2[j] + e1[i] + 1);
    }
  }
  sort(0, cnt-1);
  for(i=0; i<cnt-1; i++) {
    if(llabs(arr[i]) == llabs(arr[i+1])) {
      acc += sign(arr[i]);
      continue;
    }
    acc+=sign(arr[i]);
    if(max<acc+acc2) {
      max = acc+acc2;
      ans = llabs(arr[i])-1;
    }
    acc2+=acc*(llabs(arr[i+1])-llabs(arr[i]));
    if(max<acc2) {
      max = acc2;
      ans = llabs(arr[i+1])-2;
    }
  }
  if(llabs(arr[cnt-2]) == llabs(arr[cnt-1])) acc+=sign(arr[cnt-1]);
  if(max<acc+acc2) ans=llabs(arr[cnt-1])-1;
  printf("%d\n", ans);
  return 0;
}
