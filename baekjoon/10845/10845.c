#include <stdio.h>
#include <string.h>

int main() {
  int queue[10000], front = 0, back = 0, data, cmds;
  char cmd[10];
  scanf("%d", &cmds);
  while(cmds-- > 0) {
    scanf("%s", cmd);
    if(!strcmp(cmd, "push")) {
      scanf("%d", &data);
      queue[back++] = data;
    } else if(!strcmp(cmd, "front")) {
      if(front == back) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", queue[front]);
    } else if(!strcmp(cmd, "back")) {
      if(front == back) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", queue[back-1]);
    } else if(!strcmp(cmd, "size")) {
      printf("%d\n", back-front);
    } else if(!strcmp(cmd, "empty")) {
      printf("%d\n", front == back ? 1 : 0);
    } else if(!strcmp(cmd, "pop")) {
      if(front == back) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", queue[front++]);
    }
  }
  return 0;
}
