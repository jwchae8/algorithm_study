#include <stdio.h>

int main() {
  int i, sum=0, num, freq[1000]={0}, max_freq=-1, max_freq_index=0;
  for(i=0; i<10; i++) {
    scanf("%d", &num);
    sum += num;
    freq[num] += 1;
    if(freq[num] > max_freq) {
      max_freq = freq[num];
      max_freq_index = num;
    }
  }
  printf("%d\n%d\n", sum / 10, max_freq_index);
  return 0;
}
