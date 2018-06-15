#include <stdio.h>

int main() {
    int i, j, k; //for loop index
    int t, n, l; //test case, number of days, number of teams
    int cost[1000]; //list of daily cost
    int sum;
    double min_avg;
    scanf("%d", &t);
    for(i=0; i<t; i++) {
        min_avg = 9999999;
        scanf("%d %d", &n, &l);
        sum = 0;
        for(j=0; j<n; j++)
            scanf("%d", cost+j);
        for(j=0; j<n-l+1; j++){
            sum = 0;
            for(k=j; k<n; k++){
                sum += cost[k];
                if(k - j < l - 1)
                    continue;
                if(min_avg > (double)sum / (k-j+1))
                    min_avg = (double)sum / (k-j+1);
            }
        }
        printf("%.12f\n", min_avg);
    }
    return 0;
}
