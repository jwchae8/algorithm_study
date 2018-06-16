#include <stdio.h>

int switches[10][5] = {{0, 1, 2, -1, -1},
                       {3, 7, 9, 11, -1},
                       {4, 10, 14, 15, -1},
                       {0, 4, 5, 6, 7},
                       {6, 7, 8, 10, 12},
                       {0, 2, 14, 15, -1},
                       {3, 14, 15, -1, -1},
                       {4, 5, 7, 14, 15},
                       {1, 2, 3, 4, 5},
                       {3, 4, 5, 9, 13}};


int clocksync(int *clocks, int level) {
    int i, j, tmp, ret=9999;
    int cnt = 0;
    if(level == 10) {
        for(i=0; i<16; i++) {
            if(clocks[i] == 12)
                cnt++;
        }
        if(cnt == 16)
            return 0;
        else 
            return ret;
    }
    for(i=0; i<4; i++) {
        if((tmp = i + clocksync(clocks, level+1)) < ret)
            ret = tmp;
        for(j=0; j<5 && switches[level][j] != -1; j++) {
            clocks[switches[level][j]] += 3;
            if(clocks[switches[level][j]] > 12)
                clocks[switches[level][j]] -= 12;
        }
    }
    return ret;
}

int main() {
    int i, j; // for loop index
    int clocks[16]; // clock information
    int c; // test case
    int result;
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        for(j=0; j<16; j++) {
            scanf("%d", clocks+j);
        }
        if((result = clocksync(clocks, 0)) > 100)
            result = -1;
        printf("%d\n", result);
    }
    return 0;
}
