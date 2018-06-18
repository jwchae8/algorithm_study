#include <stdio.h>
#include <math.h>

double func(double co[6], double x, int n) {
    int i, j;
    double tmp, ret = 0.0;
    for(i=0; i<n+1; i++) {
        tmp = 1.0;
        for(j=0; j<(n-i); j++)
            tmp *= x;
        ret += co[i] * tmp;
    }
    return ret;
}

void solve(double co[6], double sol[6], int* soln, int n) {
    int i, j, extreme_num;
    double diff_co[6], extremes[10];
    if(n == 1) {
        *soln = 1;
        sol[0] = - co[1] / co[0];
        return;
    }
    if(n == 2) {
        if(co[1] * co[1] - 4 * co[0] * co[2] < 0) {
            *soln = 0;
        }
        else if(co[1] * co[1] - 4 * co[0] * co[2] == 0) {
            *soln = 1;
            sol[0] = - co[1] / co[0] / 2;
        }
        else {
            *soln = 2;
            sol[0] = (- co[1] - sqrt(co[1] * co[1] - 4 * co[0] * co[2])) / (2 * co[0]);
            sol[1] = (- co[1] + sqrt(co[1] * co[1] - 4 * co[0] * co[2])) / (2 * co[0]);
        }
        return;
    }
    for(i=0; i<n+1; i++) {
        diff_co[i] = co[i] * (n - i);
    }
    solve(diff_co, sol, soln, n-1);
    extreme_num = *soln;
    extremes[0] = -10.0;
    for(i=1; i<=extreme_num; i++) {
        extremes[i] = sol[i-1];
    }
    extremes[extreme_num+1] = 10.0;
    *soln = 0;
    for(i=0; i<extreme_num + 1; i++) {
        double x1 = extremes[i], x2 = extremes[i+1];
        double y1 = func(co, x1, n);
        double y2 = func(co, x2, n);
        if(y1 * y2 > 0) continue;
        if(y1 > y2) {
            double tmp = x1;
            x1 = x2;
            x2 = tmp;
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for(j=0; j<100; j++) {
            double midx = (x1 + x2) / 2;
            double midy = func(co, midx, n);
            if(y1 * midy > 0) {
                x1 = midx;
                y1 = midy;
            }
            else {
                x2 = midx;
                y2 = midy;
            }
        }
        sol[*soln] = (x1 + x2) / 2;
        *soln += 1;
    }
}

int main() {
    int i, j, soln;
    int c, n; // test case, max power of polynomial
    double co[6], sol[6];
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%d", &n);
        for(j=0; j<n+1; j++) {
            scanf("%lf", co+j);
        }
        soln = 0;
        solve(co, sol, &soln, n);
        for(j=0; j<soln; j++) {
            printf("%.12lf ", sol[j]);
        }
        printf("\n");
    }
    return 0;
}
