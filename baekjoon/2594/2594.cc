#include <cstdio>
#include <algorithm>

int main() {
  int i, j, n, s[51], e[51], cur=0, free=600, ans=0;
  std::scanf("%d", &n);
  for(i=0; i<n; i++) {
    std::scanf("%d %d", s+i, e+i);
    s[i] = s[i] < 1010 ? 600 : (s[i] / 100) * 60 + s[i] % 100 - 10;
    e[i] = e[i] > 2150 ? 1320 : (e[i] / 100) * 60 + e[i] % 100 + 10;
  }
  std::sort(s, s+n);
  std::sort(e, e+n);
  for(i=0, j=0; i<n || j<n;) {
    if(i<n && s[i] < e[j]) {
      if(!cur++ && ans < s[i] - free) ans = s[i] - free;
      i++;
    } else {
      if(!--cur) free=e[j];
      j++;
    }
  }
  if(1320 - free > ans) ans = 1320 - free;
  std::printf("%d\n", ans);
  return 0;
}
