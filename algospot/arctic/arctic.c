#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    int c, n; // test case, number of bases
    int visited[100], queue[200];
    double x[100], y[100];
    double distance[100][100];
    double min, max, mid;
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%d", &n);
        for(j=0; j<n; j++) {
            scanf("%lf %lf", x+j, y+j);
        }
        for(j=0; j<n; j++) {
            for(k=0; k<n; k++) {
                distance[j][k] = sqrt((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]));
            }
        }
        min = 0; max = sqrt(2000000);
        mid = (min + max) / 2;
        //while(max - mid > 1e-4) {
        for(k=0; k<100; k++) {
            memset(visited, 0, sizeof(int) * n);
            memset(queue, 0, sizeof(int) * 2 * n);
            int traverse = 0;
            int head = 0, tail = 0;
            queue[tail++] = 0;
            visited[0] = 1;
            while(head < tail) {
                int q = queue[head++];
                traverse++;
                for(j=0; j<n; j++) {
                    if(!visited[j] && distance[q][j] <= mid) {
                        queue[tail++] = j;
                        visited[j] ++;
                    }
                }
            }
            if(traverse == n)
                max = mid;
            else
                min = mid;
            mid = (min + max) / 2;
        }
        printf("%.2lf\n", mid);
    }
    return 0;
}
