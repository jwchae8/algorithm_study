#include <stdio.h>
#include <string.h> 


int main() {
    int c, n, k; // test case, number of boxes, number of kids
    int i, j; // for loop index
    int result1, result2;
    int dolls[100000]; // number of dolls in each box
    int psum[100001]; // partial sum of dolls
    long long sorted_psum[100001]; // sorted partial sum of dolls
    int dp_table[100001];
    int prev_table[100001];

    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%d %d", &n, &k);
        for(j=0; j<n; j++) {
            scanf("%d", dolls + j);
        }
        psum[0] = 0;
        for(j=0; j<n; j++) {
            psum[j+1] = (psum[j] + dolls[j]) % k;
        }
        memset(sorted_psum, 0, sizeof(long long) * 100001);
        for(j=0; j<=n; j++) {
            sorted_psum[psum[j]]++;
        }
        result1 = 0;
        for(j=0; j<k; j++) {
            if(sorted_psum[j] > 1) {
                result1 = (result1 + ((sorted_psum[j] * (sorted_psum[j] - 1)) / 2)) % 20091101;
            }
        }
        memset(prev_table, -1, sizeof(int) * 100001);
        memset(dp_table, 0, sizeof(int) * 100001);
        for(j=0; j<=n; j++) {
            if (j > 0)
                dp_table[j] = dp_table[j-1];
            else
                dp_table[j] = 0;
            int prev = prev_table[psum[j]];
            if(prev != -1)  {
                if(dp_table[j] < dp_table[prev] + 1)
                    dp_table[j] = dp_table[prev] + 1;
            }
            prev_table[psum[j]] = j;
        }
        result2 = dp_table[n];
        printf("%d %d\n", result1, result2);
    }
    return 0;
}
