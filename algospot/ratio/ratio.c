#include <stdio.h>

int main() {
    int i, j; // for loop index
    long long n, m; // game played, game won
    int c; // test case
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%lld %lld", &n, &m);
        long long min = 1, max = 2000000000, mid;
        for(j=0; j<100; j++) {
            mid = (min + max) / 2;
            int before = (100 * m) / n;
            int after =  (100 * (m + mid)) /(n + mid);
            if(before < after)
                max = mid;
            else
                min = mid;
        }
        if(max == 2000000000)
            max = -1;
        printf("%lld\n", max);
    }
    return 0;
}
