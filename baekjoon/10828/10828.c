#include <stdio.h>
#include <string.h>

int main() {
  int stack[100000], top = 0, data, cmds;
  char cmd[10];
  scanf("%d", &cmds);
  while(cmds-- > 0) {
    scanf("%s", cmd);
    if(!strcmp(cmd, "push")) {
      scanf("%d", &data);
      stack[top++] = data;
    } else if(!strcmp(cmd, "top")) {
      if(top == 0) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", stack[top-1]);
    } else if(!strcmp(cmd, "size")) {
      printf("%d\n", top);
    } else if(!strcmp(cmd, "empty")) {
      printf("%d\n", top == 0 ? 1 : 0);
    } else if(!strcmp(cmd, "pop")) {
      if(top == 0) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", stack[--top]);
    }
  }
  return 0;
}
