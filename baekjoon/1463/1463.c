#include <stdio.h>
#include <string.h>

int dp_table[1000000];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int n) {
    int ret = 99999999;
    if(n == 1)
        return 0;
    if(dp_table[n] != -1) 
        return dp_table[n];
    if(n % 3 == 0) 
        ret = min(ret, 1 + solve(n / 3));
    if(n % 2 == 0)
        ret = min(ret, 1 + solve(n / 2));
    ret = min(ret, 1 + solve(n - 1));
    dp_table[n] = ret;
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(dp_table, -1, sizeof(int) * (n+1));
    printf("%d\n", solve(n));
    return 0;
}
