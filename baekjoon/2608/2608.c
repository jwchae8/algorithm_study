#include <stdio.h>

int main() {
  int roman_num[26];
  char s[50];
  int i = 0, n = 0;
  roman_num['M'-'A'] = 1000;
  roman_num['D'-'A'] = 500;
  roman_num['C'-'A'] = 100;
  roman_num['L'-'A'] = 50;
  roman_num['X'-'A'] = 10;
  roman_num['V'-'A'] = 5;
  roman_num['I'-'A'] = 1;
  scanf("%s", s);
  while(s[i] != 0) {
    if(s[i+1] == 0) {
      n += roman_num[s[i] - 'A'];
      break;
    } else {
      if(roman_num[s[i] - 'A'] < roman_num[s[i+1] - 'A']) {
        n += roman_num[s[i+1] - 'A'] - roman_num[s[i] - 'A'];
        i += 2;
      } else {
        n += roman_num[s[i] - 'A'];
        i += 1;
      }
    }
  }
  i = 0;
  scanf("%s", s);
  while(s[i] != 0) {
    if(s[i+1] == 0) {
      n += roman_num[s[i] - 'A'];
      break;
    } else {
      if(roman_num[s[i] - 'A'] < roman_num[s[i+1] - 'A']) {
        n += roman_num[s[i+1] - 'A'] - roman_num[s[i] - 'A'];
        i += 2;
      } else {
        n += roman_num[s[i] - 'A'];
        i += 1;
      }
    }
  }
  printf("%d\n", n);
  if(n > 999) {
    i = n / 1000;
    while(i-- > 0)
      printf("M");
    n %= 1000;
  } if(n > 99) {
    i = n / 100;
    if(i == 9) {
      printf("CM");
    } else if(i == 4) {
      printf("CD");
    } else {
      if(i >= 5) {
        printf("D");
        i -= 5;
      }
      while(i-- > 0)
        printf("C");
    }
    n %= 100;
  } if(n > 9) {
    i = n / 10;
    if(i == 9) {
      printf("XC");
    } else if(i == 4) {
      printf("XL");
    } else {
      if(i >= 5) {
        printf("L");
        i -= 5;
      }
      while(i-- > 0)
        printf("X");
    }
    n %= 10;
  }
  if(n == 9) {
    printf("IX");
  } else if(n == 4) {
    printf("IV");
  } else {
    if(n >= 5) {
      printf("V");
      n -= 5;
    }
    while(n-- > 0)
      printf("I");
  }
  return 0;
}
