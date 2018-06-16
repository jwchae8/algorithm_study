#include <stdio.h>

int fence(int h[20000], int l, int r) {
    int i;
    int cur, midl = (l+r) / 2, midr = (l+r) / 2 + 1;
    int max, left_max, right_max;
    if(l == r)
        return h[l];
    left_max = fence(h, l, (l+r) / 2);
    right_max = fence(h, (l+r) / 2 + 1, r);
    max = (left_max > right_max) ? left_max : right_max;
    cur = (h[midl] < h[midr]) ? h[midl] : h[midr];
    max = (2 * cur > max) ? 2 * cur : max;
    while(midl > l || midr < r) {
        if(midl > l && (midr == r || h[midl-1] > h[midr+1])) {
            midl--;
            cur = (cur > h[midl]) ? h[midl] : cur;
        }
        else{
            midr++;
            cur = (cur > h[midr]) ? h[midr] : cur;
        }
        max = (cur * (midr - midl + 1) > max) ? cur * (midr - midl + 1) : max;
    }
    return max;
}

int main() {
    int i, j; // for loop index
    int c, n; // test case, number of input
    int h[20000]; // input
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%d", &n);
        for(j=0; j<n; j++) {
            scanf("%d", h + j);
        }
        printf("%d\n", fence(h, 0, n-1));
    }
    return 0;
}
