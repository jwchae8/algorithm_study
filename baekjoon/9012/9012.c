#include <stdio.h>
#include <string.h>

int top;

void push() {
  top++;
}

int pop() {
  top--;
  return top >= 0;
}

int main() {
  int i, j, n;
  char ps[51];
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    scanf("%s", ps);
    top = 0;
    for(j=0; j<strlen(ps); j++) {
      if(ps[j] == '(')
        push();
      else {
        if(!pop()) {
          break;
        }
      }
    }
    printf("%s\n", top == 0 ?  "YES" : "NO");
  }
  return 0;
}
