#include <stdio.h>

void merge(double x[1000], int l, int r) {
    double tmp[1000];
    int i;
    int left = l, right = (l+r)/2+1, cur = l;
    while(left <= (l+r) / 2 || right <= r) {
        if(left <= (l+r) / 2 && (right > r || x[left] > x[right])) {
            tmp[cur++] = x[left++];
        }
        else
            tmp[cur++] = x[right++];
    }
    for(i=l; i<=r; i++)
        x[i] = tmp[i];
}
void msort(double x[1000], int l, int r) {
    if(l==r)
        return;
    msort(x, l, (l+r)/2);
    msort(x, (l+r)/2+1, r);
    merge(x, l, r);
}

int main() {
    int i, j, l;
    int t, n, k; // test case, current subjects, required subjects
    int r[1000], c[1000];
    double x[1000];
    double min, max, mid, sum;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        scanf("%d %d", &n, &k);
        for(j=0; j<n; j++) {
            scanf("%d %d", r + j, c + j);
        }
        min = 0.0;
        max = 1.0;
        mid = (min + max) / 2;
        for(j=0; j<100; j++) {
            for(l = 0; l < n; l++) {
                x[l] = mid * c[l] - r[l];
            }
            msort(x, 0, n-1);
            sum = 0.0;
            for(l = 0; l < k; l++)
                sum += x[l];
            if(sum >=0)
                max = mid;
            else
                min = mid;
            mid = (min + max) / 2;
        }
        printf("%.10lf\n", mid);
    }
    return 0;
}
