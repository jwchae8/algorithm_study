#include<stdio.h>

int main() {
    int i, j; // for loop index
    int c, n, k; // test case, number of cities, sign target
    int l[5000], m[5000], g[5000];
    int min, max, mid;
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        min = 8030001;
        scanf("%d %d", &n, &k);
        for(j=0; j<n; j++){
            scanf("%d %d %d", l+j, m+j, g+j);
            if(min > l[j] - m[j])
                min = l[j] - m[j];
        }
        max = 8030000;
        mid = (min + max) / 2;
        while (min+1 < max) {
            int signs = 0;
            for(j=0; j<n; j++) {
                if(l[j] - m[j] <= mid) {
                    signs += (((mid > l[j]) ? l[j] : mid) - (l[j] - m[j])) / g[j] + 1;
                }
            }
            if(signs >= k)
                max = mid;
            else
                min = mid;
            mid = (min + max) / 2;
        }
        printf("%d\n", max);
    }
    return 0;
}
