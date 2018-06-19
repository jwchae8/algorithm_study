#include <stdio.h>
#include <string.h>

int divisors[10000000];

int main() {
    int i, j;
    int c, n, lo, hi;
    memset(divisors, 0, sizeof(int) * 10000000);
    for(i=1; i<=10000000; i++) {
        for(j=i; j<=10000000; j+=i) {
            divisors[j]+= 1;
        }
    }
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        int sum = 0;
        scanf("%d %d %d", &n, &lo, &hi);
        for(j=lo; j<=hi; j++) {
            if(divisors[j] == n)
                sum ++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
