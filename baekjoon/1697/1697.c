#include <stdio.h>

int visited[100001];
int queue[100000];
int front, rear;

void push(int n, int t) {
  queue[front++] = n;
  visited[n] = t;
}

int pop() {
  return queue[rear++];
}

int main() {
  int n, k, cur;
  scanf("%d %d", &n, &k);
  push(n, 0);
  do {
    cur = pop();
    if(cur == k)
      break;
    if(!visited[cur - 1] && cur - 1 >= 0) {
      push(cur - 1, visited[cur] + 1);
    }
    if(!visited[cur + 1] && cur + 1 <= 100000) {
      push(cur + 1, visited[cur] + 1);
    }
    if(!visited[cur * 2] && cur * 2 <= 100000) {
      push(cur * 2, visited[cur] + 1);
    }
  } while(front != rear);
  printf("%d\n", visited[k]);
  return 0;
}
