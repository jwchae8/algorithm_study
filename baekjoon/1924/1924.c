#include <stdio.h>

int main() {
  int dates[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
  char days[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%s\n", days[(dates[x-1] + y-1) % 7]);
  return 0;
}
