#include <stdio.h>

int board[100][100];
int possible[100][100];

void jumpgame(int x, int y, int n) {
    int i;
    int mov = board[x][y];
    if(!possible[x][y+mov] && y+mov < n) {
        possible[x][y+mov] = 1;
        jumpgame(x,y+mov, n);
    }
    if(!possible[x+mov][y] && x+mov <n) {
        possible[x+mov][y] = 1;
        jumpgame(x+mov,y, n);
    }

}

int main() {
    int c; // test case
    int n; // size of board
    int i, j, k;
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%d", &n);
        for(j=0; j<n; j++) {
            for(k=0; k<n; k++) {
                scanf("%d", &board[j][k]);
                possible[j][k] = 0;
            }
        }
        jumpgame(0, 0, n);
        if(possible[n-1][n-1])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
