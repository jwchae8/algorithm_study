#include <stdio.h>

int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int i, arr[6], cnt=0, tmp, tmp2;
  for(i=0; i<6; i++) scanf("%d", arr+i);
  while(1) {
    if(arr[5]) {
      arr[5] -= 1;
    } else if(arr[4]) {
      arr[4] -= 1;
      arr[0] -= min(arr[0], 11);
    } else if(arr[3]) {
      arr[3] -= 1;
      tmp = min(arr[1], 5);
      arr[1] -= tmp;
      arr[0] -= min(arr[0], 20 - tmp*4);
    } else if(arr[2]) {
      tmp = min(arr[2], 4);
      arr[2] -= tmp;
      if(tmp < 4) {
        tmp2 = min(arr[1], (3-tmp)*2+1);
        arr[1] -= tmp2;
        arr[0] -= min(arr[0], 36 - tmp*9 - tmp2*4);
      }
    } else if(arr[1]) {
      tmp = min(arr[1], 9);
      arr[1] -= tmp;
      arr[0] -= min(arr[0], 36 - tmp*4);
    } else if(arr[0]) {
      arr[0] -= min(arr[0], 36);
    } else {
      break;
    }
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
