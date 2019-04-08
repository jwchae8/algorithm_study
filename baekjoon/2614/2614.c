#include <stdio.h>

int frogs[21][2] = {{1,1},{2,1},{2,2},
                    {3,1},{3,2},{3,3},
                    {4,1},{4,2},{4,3},
                    {4,4},{5,1},{5,2},
                    {5,3},{5,4},{5,5},
                    {6,1},{6,2},{6,3},
                    {6,4},{6,5},{6,6}};
int n, arr[202];
int ans_cnt=100, ans_frogs[21];
int total, cur_cnt, cur_frogs[21];
int nonzero;


void addfrogs(int f, int c) {
  int i;
  for(i=frogs[f][1]; i<=n; i+=frogs[f][0]) {
    if(arr[i] && arr[i] == c)
      nonzero--;
    arr[i] -= c;
    total -= c;
  }
  cur_cnt += c;
  cur_frogs[f] += c;
}

void rmfrogs(int f, int c) {
  int i;
  for(i=frogs[f][1]; i<=n; i+=frogs[f][0]) {
    if(!arr[i] && c)
      nonzero++;
    arr[i] += c;
    total += c;
  }
  cur_cnt -= c;
  cur_frogs[f] -= c;
}

int maxfrogs(int f) {
  int i, min = 100;
  if(frogs[f][0] + frogs[f][1] > n)
    return 0;
  if(f == 2 && cur_frogs[1]) 
    return 0;
  if(f == 5 && cur_frogs[3] * cur_frogs[4])
    return 0;
  if(f == 8 && cur_frogs[6])
    return 0;
  if(f == 9 && cur_frogs[7])
    return 0;
  if(f == 14 && cur_frogs[10] * cur_frogs[11] * cur_frogs[12] * cur_frogs[13])
    return 0;
  if(f == 18 && cur_frogs[15])
    return 0;
  if(f == 19 && (cur_frogs[16] || cur_frogs[17] * cur_frogs[15]))
    return 0;
  if(f == 20 && (cur_frogs[17] || cur_frogs[18] * cur_frogs[16]))
    return 0;
  if(f == 11)
    min = arr[7] >= arr[1] ? arr[7] - arr[1] : -1;
  if(f == 12)
    min = arr[8] >= arr[2] ? arr[8] - arr[2] : -1;
  if(f == 13)
    min = arr[9] >= arr[3] ? arr[9] - arr[3] : -1;
  if(f == 14)
    min = arr[10] >= arr[4] ? arr[10] - arr[4] : -1;

  for(i=frogs[f][1]; i<=n; i+=frogs[f][0])
    min = min < arr[i] ? min : arr[i];
  return min < ans_cnt - cur_cnt ? min : -1;
}

int minfrogs(int f) {
  if(frogs[f][0] + frogs[f][1] > n)
    return 0;
  if(f == 9 && n >= 12) {
    return (arr[7] - arr[1]) > (arr[12] - arr[6]) ? 100 : arr[12] - arr[6] - arr[7] + arr[1];
  }
  if(f == 10) {
    if(n < 12)
      return arr[6];
    else {
      if(arr[7] - arr[1] == arr[12] - arr[6]) { 
        if(arr[7] - arr[1] >= 0)
          return 0;
        else
          return arr[1] - arr[7];
      }
      else
        return 100;
    }
  }
  if(f == 11)
    return arr[7] >= arr[1] ? arr[7] - arr[1] : 100;
  if(f == 12)
    return arr[8] >= arr[2] ? arr[8] - arr[2] : 100;
  if(f == 13)
    return arr[9] >= arr[3] ? arr[9] - arr[3] : 100;
  if(f == 14)
    return arr[10] >= arr[4] ? arr[10] - arr[4] : 100;
  if(f >= 15)
    return arr[frogs[f][1]];
  return 0;
}

void solve(int f) {
  int i, tmp;
  int first=0, second=0;
  if(nonzero == 1)
    return;
  if(nonzero == 2) {
    for(i=1; i<=n; i++) {
      if(!first && arr[i]) {
        first = i;
        continue;
      }
      if(!second && arr[i]) {
        second = i;
        break;
      }
    }
    if(second - first > 6 || second - first < frogs[f][0] || arr[first] != arr[second] || second - first < first || second - first <= n - second)
      return;
    else {
      tmp = arr[first];
      addfrogs((second - first) * (second - first - 1) / 2 + (first - 1), tmp);
      if(cur_cnt <= ans_cnt) {
        ans_cnt = cur_cnt;
        for(i=0; i<21; i++) ans_frogs[i] = cur_frogs[i];
      }
      rmfrogs((second - first) * (second - first - 1) / 2 + (first - 1), tmp);
      return;
    }
  }
  if(!nonzero) {
    if(cur_cnt <= ans_cnt) {
      ans_cnt = cur_cnt;
      for(i=0; i<21; i++) ans_frogs[i] = cur_frogs[i];
    }
    return;
  }
  if(((n-1)/frogs[f][0] + 1) * (ans_cnt - cur_cnt) < total)
    return;
  first = 0; second = 0;
  for(i=1; i<=frogs[f][0]; i++)
    first += arr[i];
  for(i=frogs[f][0]+1; i<=frogs[f][0]+6; i++)
    second += arr[i];
  if(first > second)
    return;
  if(f == 21) return;
  for(i=maxfrogs(f); i>=minfrogs(f); i--) {
    addfrogs(f, i);
    solve(f+1);
    rmfrogs(f, i);
  }
}

int main() {
  int i, j;
  scanf("%d", &n);
  for(i=1; i<=n; i++){ 
    scanf("%d", arr+i);
    if(arr[i]) nonzero++;
    total += arr[i];
  }
  solve(0);
  printf("%d\n", ans_cnt);
  for(i=0; i<21; i++) 
    for(j=0; j<ans_frogs[i]; j++) 
      printf("%d %d\n", frogs[i][1], frogs[i][0]);
  int tmparr[202] = {0};
  return 0;
}
