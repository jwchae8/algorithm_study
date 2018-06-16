#include <stdio.h>

const int dx[8] = {0, 1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {1, 0, 1, 1, 0, 1, 1, 1}; 
int boardcover(int board[20][20], int whites, int h, int w) {
    int ret = 0;
    int i, j, k;
    if(whites == 0) return 1;
    for(i=0; i<h; i++) {
        for(j=0; j<w; j++) {
            if(board[i][j]) continue;
            for(k=0; k<8; k+=2) {
                if(i+dy[k] < 0 || i+dy[k] >= h || j+dx[k] < 0 || j+dx[k] >= w) // range check
                    continue;
                if(i+dy[k+1] < 0 || i+dy[k+1] >= h || j+dx[k+1] < 0 || j+dx[k+1] >= w) // range check
                    continue;
                if(board[i+dy[k]][j+dx[k]] == 0 && board[i+dy[k+1]][j+dx[k+1]] == 0) {
                    board[i][j] = 1;
                    board[i+dy[k]][j+dx[k]] = 1;
                    board[i+dy[k+1]][j+dx[k+1]] = 1;
                    ret += boardcover(board, whites - 3, h, w);
                    board[i][j] = 0;
                    board[i+dy[k]][j+dx[k]] = 0;
                    board[i+dy[k+1]][j+dx[k+1]] = 0;
                }
            }
            return ret;
        }
    }
    return 0;
}

int main() {
    int i, j, k; // for loop index
    int c, h, w; // test case, board height, board width
    int board[20][20]; // board color for each cell
    int whites; // number of white cell
    char input[21];
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        whites = 0;
        scanf("%d %d", &h, &w);
        for(j=0; j<h; j++) {
            scanf("%s", input);
            for(k=0; k<w; k++){
                if(input[k] == '#')
                    board[j][k] = 1;
                else {
                    board[j][k] = 0;
                    whites++;
                }
            }
        }
        if(whites % 3)
            printf("0\n");
        else
            printf("%d\n",boardcover(board, whites, h, w));
    }
    return 0;
}
