#include <stdio.h>
#include <string.h>

int dp_table[10][1 << 12];

int graduate(int rlist[12], int slist[10], int n, int k, int m, int l, int s, int d) {
    int i;
    int available = 0;
    int ret = 9999, tmp;
    if(__builtin_popcount(d) >= k)
        return 0;
    if(s == m)
        return 9999;
    if(dp_table[s][d] != -1)
        return dp_table[s][d];
    available = (slist[s] & ~d);
    for(i = 0; i < n; i++) {
        if(available & (1 << i)) {
            if((rlist[i] & d) != rlist[i]) {
                available &= ~(1 << i);
            }
        }
    }
    for(i = available; i > 0; i = ((i - 1) & available)) {
        if(__builtin_popcount(i) > l)
            continue;
        if((tmp = graduate(rlist, slist, n, k, m, l, s+1, d | i) + 1) < ret)
            ret = tmp;
    }
    if((tmp = graduate(rlist, slist, n, k, m, l, s+1, d)) < ret)
        ret = tmp;
    dp_table[s][d] = ret;
    return ret;
}

int main() {
    int c, n, k, m, l; // test case, number of subjects, number of required subjects, remaining semesters, max subjects per semester
    int i, j, x; // for loop index
    int rcount, r, rlist[12]; // precedence subjects
    int scount, s, slist[10];
    int result;
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        for(j=0; j<12; j++) {
            rlist[j] = 0;
        }
        for(j=0; j<10; j++) {
            slist[j] = 0;
        }
        scanf("%d %d %d %d", &n, &k, &m, &l);
        for(j=0; j<n; j++) {
            scanf("%d", &rcount);
            for(x=0; x<rcount; x++) {
                scanf("%d", &r);
                rlist[j] |= (1 << r);
            }
        }
        for(j=0; j<m; j++) {
            scanf("%d", &scount);
            for(x=0; x<scount; x++) {
                scanf("%d", &s);
                slist[j] |= (1 << s);
            }
        }
        memset(dp_table, -1, sizeof(int) * 10 * (1 << 12));
        if((result = graduate(rlist, slist, n, k, m, l, 0, 0)) >= 9999)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", result);
    }
    return 0;
}
