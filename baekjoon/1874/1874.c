#include <stdio.h>

int stack[100001];
int trace[200002];
int top;
int count;

void push(int n) {
  stack[top++] = n;
}

int pop() {
  return stack[--top];
}


int main() {
  int i, j, n, num, cur = 1;
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%d", &num);
    if(top == 0 || num > stack[top-1]) {
      while(cur <= num) {
        push(cur++);
        trace[count++] = 1;
      }
      pop();
      trace[count++] = -1;
    } else if(num < stack[top-1]) {
      printf("NO\n");
      count = 0;
      break;
    } else {
      pop();
      trace[count++] = -1;
    }
  }
  for(i=0; i<count; i++) {
    printf("%c\n", trace[i] == 1 ? '+' : '-');
  }
  return 0;
}
