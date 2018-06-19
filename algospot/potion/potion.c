#include <stdio.h>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main() {
    int c, n;
    int i, j;
    int ratio[200], already[200];
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%d", &n);
        for(j=0; j<n; j++)
            scanf("%d", ratio + j);
        for(j=0; j<n; j++)
            scanf("%d", already + j);
        int g = ratio[0];
        int ans, max;
        for(j=1; j<n; j++) 
            g = gcd(g, ratio[j]);
        max = g;
        for(j=0; j<n; j++) {
            ans = (already[j] * g + ratio[j] - 1) / ratio[j];
            if(max < ans)
                max = ans;
        }
        for(j=0; j<n; j++) {
            printf("%d ", ratio[j] * max / g - already[j]);
        }
        printf("\n");
    }
    return 0;
}
