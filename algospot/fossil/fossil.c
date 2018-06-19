#include <stdio.h>

int main() {
    int i, j, k;
    int c, n, m; // test case, number of points for each
    double ax[100], ay[100], bx[100], by[100], upper_halfx[100][2], upper_halfy[100][2], lower_halfx[100][2], lower_halfy[100][2];
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        double awest=101.0, aeast=0.0, anorth=0.0, asouth=101.0, bwest=101.0, beast=0.0, bnorth=0.0, bsouth=101.0;
        scanf("%d %d", &n, &m);
        for(j=0; j<n; j++) {
            scanf("%lf %lf", ax + j, ay + j);
            if(ax[j] < awest)
                awest = ax[j];
            if(ax[j] > aeast)
                aeast = ax[j];
            if(ay[j] > anorth)
                anorth = ay[j];
            if(ay[j] < asouth)
                asouth = ay[j];
        }
        for(j=0; j<m; j++) {
            scanf("%lf %lf", bx + j, by + j);
            if(bx[j] < bwest)
                bwest = bx[j];
            if(bx[j] > beast)
                beast = bx[j];
            if(by[j] > bnorth)
                bnorth = by[j];
            if(by[j] < bsouth)
                bsouth = by[j];
        }
        /*if(awest >= beast || aeast <= bwest || anorth <= bsouth || asouth >= bnorth) {
            printf("%.6lf\n", 0.0);
            continue;
        }*/
        int uppern=0, lowern=0;
        for(j=0; j<m; j++) {
            if(bx[j] > bx[(j+1)%m]) {
                upper_halfx[uppern][0] = bx[j];
                upper_halfx[uppern][1] = bx[(j+1)%m];
                upper_halfy[uppern][0] = by[j];
                upper_halfy[uppern++][1] = by[(j+1)%m];
            }
            if(bx[j] < bx[(j+1)%m]) {
                lower_halfx[lowern][0] = bx[j];
                lower_halfx[lowern][1] = bx[(j+1)%m];
                lower_halfy[lowern][0] = by[j];
                lower_halfy[lowern++][1] = by[(j+1)%m];
            }
        }
        for(j=0; j<n; j++) {
            if(ax[j] < ax[(j+1)%n]) {
                lower_halfx[lowern][0] = ax[j];
                lower_halfx[lowern][1] = ax[(j+1)%n];
                lower_halfy[lowern][0] = ay[j];
                lower_halfy[lowern++][1] = ay[(j+1)%n];
            }
            if(ax[j] > ax[(j+1)%n]) {
                upper_halfx[uppern][0] = ax[j];
                upper_halfx[uppern][1] = ax[(j+1)%n];
                upper_halfy[uppern][0] = ay[j];
                upper_halfy[uppern++][1] = ay[(j+1)%n];
            }
        }
        double min, max, onethird, twothird, onethirdy, twothirdy;
        double minupy, maxlowy, upy, lowy;
        if(awest < bwest)
            min = bwest;
        else
            min = awest;
        if(aeast > beast)
            max = beast;
        else
            max = aeast;
        if(max < min) {
            printf("%.6lf\n", 0.0);
            continue;
        }
        for(j=0; j<100; j++) {
            minupy = 100.0;
            maxlowy = 0.0;
            onethird = (min * 2 + max) / 3.0;
            twothird = (max * 2 + min) / 3.0;
            for(k=0; k<uppern; k++) {
                if(upper_halfx[k][0] >= onethird && upper_halfx[k][1] <= onethird) {
                    upy = upper_halfy[k][0] + (upper_halfy[k][0] - upper_halfy[k][1]) / (upper_halfx[k][0] - upper_halfx[k][1]) * (onethird - upper_halfx[k][0]);
                    if(minupy > upy)
                        minupy = upy;
                }
            }
            for(k=0; k<lowern; k++) {
                if(lower_halfx[k][0] <= onethird && lower_halfx[k][1] >= onethird) {
                    lowy = lower_halfy[k][0] + (lower_halfy[k][0] - lower_halfy[k][1]) / (lower_halfx[k][0] - lower_halfx[k][1]) * (onethird - lower_halfx[k][0]);
                    if(maxlowy < lowy)
                        maxlowy = lowy;
                }
            }
            onethirdy = minupy - maxlowy;
            minupy = 100.0;
            maxlowy = 0.0;
            for(k=0; k<uppern; k++) {
                if(upper_halfx[k][0] >= twothird && upper_halfx[k][1] <= twothird) {
                    upy = upper_halfy[k][0] + (upper_halfy[k][0] - upper_halfy[k][1]) / (upper_halfx[k][0] - upper_halfx[k][1]) * (twothird - upper_halfx[k][0]);
                    if(minupy > upy)
                        minupy = upy;
                }
            }
            for(k=0; k<lowern; k++) {
                if(lower_halfx[k][0] <= twothird && lower_halfx[k][1] >= twothird) {
                    lowy = lower_halfy[k][0] + (lower_halfy[k][0] - lower_halfy[k][1]) / (lower_halfx[k][0] - lower_halfx[k][1]) * (twothird - lower_halfx[k][0]);
                    if(maxlowy < lowy)
                        maxlowy = lowy;
                }
            }
            twothirdy = minupy - maxlowy;
            if(onethirdy > twothirdy)
                max = twothird;
            else
                min = onethird;
        }
        printf("%.10lf\n", (twothirdy > 0.0) ? twothirdy : 0.0);
    }
    return 0;
}
