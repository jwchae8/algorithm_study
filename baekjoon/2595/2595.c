#include <stdio.h>

struct node {
  int mod;
  int prev;
  int cur;
  int cnt;
} queue[100000];

int visit[30000];
int front, rear;
char ans[100000];

void push(int mod, int prev, int cur, int cnt) {
  int rear_val = rear % 100000;
  queue[rear_val].mod = mod;
  queue[rear_val].prev = prev;
  queue[rear_val].cur = cur;
  queue[rear_val].cnt = cnt;
  rear++;
}

struct node pop() {
  int front_val = front % 100000;
  front++;
  return queue[front_val];
}

int main() {
  int i, j, n, test, flag, ans_len=100000;
  int min, max;
  struct node cur;
  scanf("%d", &n);
  for(i=1; i<=9; i++) {
    test=0; flag=0;
    for(j=1; j<=n; j++) {
      test = (test*10+i)%n;
      if(!test) {
        flag = 1;
        break;
      }
    }
    if(flag && j<ans_len) {
      ans_len=j;
      ans[j--]=0;
      while(j>=0)ans[j--]=i+'0';
    }
  }
  if(ans_len == 100000) {
    for(i=1; i<=9; i++) {
      for(j=0; j<=9; j++) {
        if(i-j) {
          front=0;rear=0;
          max=i>j?i:j;min=i<j?i:j;
          push(i, -1, i, 1); flag=0;
          while(front < rear) {
            cur = pop();
            if(!cur.mod) {
              flag = 1;
              break;
            }
            if(visit[(cur.mod*10+min)%n] != i*10+j) {
              push((cur.mod*10+min)%n,front-1,min,cur.cnt+1);
              visit[(cur.mod*10+min)%n] = i*10+j;
            }
            if(visit[(cur.mod*10+max)%n] != i*10+j) {
              push((cur.mod*10+max)%n,front-1,max,cur.cnt+1);
              visit[(cur.mod*10+max)%n] = i*10+j;
            }
          }
          if(flag && cur.cnt<ans_len) {
            ans_len=cur.cnt;
            ans[cur.cnt] = 0;
            while(cur.prev != -1) {
              ans[cur.cnt-1]=cur.cur+'0';
              cur=queue[cur.prev];
            }
            ans[0] = cur.cur+'0';
          }
        }
      }
    }
  }
  printf("%s\n", ans);
  return 0;
}
