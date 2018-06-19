#include <stdio.h>
#include <string.h>

int dp_table[10000];

int difficulty_measure(char num[10001], int len, int digit) {
    int i, cnt = 0;
    for(i=digit; i<digit+len - 1; i++) {
        if(num[i] == num[i+1])
            cnt++;
    }
    if(cnt == len - 1)
        return 1;
    cnt = 0;
    for(i=digit; i<digit+len-1; i++) {
        if(num[i] == num[i+1] + 1)
            cnt++;
    }
    if(cnt == len - 1)
        return 2;
    cnt = 0;
    for(i=digit; i<digit+len-1; i++) {
        if(num[i] == num[i+1] - 1)
            cnt++;
    }
    if(cnt == len - 1)
        return 2;
    cnt = 0;
    for(i=digit; i<digit+len-2; i++) {
        if(num[i] == num[i+2])
            cnt++;
    }
    if(cnt == len - 2)
        return 4;
    cnt = 0;
    for(i=digit; i<digit+len-2; i++) {
        if(num[i] - num[i+1] == num[i+1] - num[i+2])
            cnt++;
    }
    if(cnt == len - 2)
        return 5;
    return 10;
}

int solve(char num[10001], int digit) {
    if(digit >= strlen(num))
        return 0;
    if(dp_table[digit] != -1)
        return dp_table[digit];
    int i, min = 987654321, difficulty;
    for(i=3; i<=5; i++) {
        difficulty = difficulty_measure(num, i, digit) + solve(num, digit+i);
        if(min > difficulty)
            min = difficulty;
    }
    dp_table[digit] = min;
    return min;
}

int main() {
    int i;
    int c;
    char num[10001];
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%s", num);
        memset(dp_table, -1, sizeof(int) * 10000);
        printf("%d\n", solve(num, 0));
    }
    return 0;
}
