#include <stdio.h>

int main() {
    int i, j;
    int c;
    double total, interest;
    int months;
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%lf %d %lf", &total, &months, &interest);
        interest = interest / 12.0 / 100.0;
        double min = 0.0, max = 100000000.0 * (1.0 + interest), mid;
        for(j=0; j<100; j++) {
            mid = (min + max) / 2.0;
            double remain = total;
            int remain_time = months;
            while(remain_time > 0) {
                remain *= (1.0 +interest);
                remain -= mid;
                remain_time--;
            }
            if(remain > 0)
                min = mid;
            else
                max = mid;
        }
        printf("%.10lf\n", max);
    }
    return 0;
}
