#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int i, n, b, ans=0, end=0;
  std::vector<std::pair<int, int> > sched(100);
  std::scanf("%d %d", &n, &b);
  for(i=0;i<n;i++)std::scanf("%d %d", &sched[i].first, &sched[i].second);
  std::sort(sched.begin(), sched.begin()+n);
  ans += sched[0].first;
  for(i=1;i<n;i++) {
    end = ans + sched[i-1].second + b;
    ans = end > sched[i].first ? end : sched[i].first;
  }
  std::printf("%d\n", ans+sched[n-1].second + b);
  return 0;
}
