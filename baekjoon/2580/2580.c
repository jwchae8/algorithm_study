#include <stdio.h>

int board[9][9];
int blank;

void sudoku() {
  int candidate[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  int i, j, k;
  if(!blank) return;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      if(!board[i][j]) {
        for(k=0; k<9; k++) {
          if(k == j) continue;
          if(board[i][k]) candidate[board[i][k]-1] = 0;
        }
        for(k=0; k<9; k++) {
          if(k == i) continue;
          if(board[k][j]) candidate[board[k][j]-1] = 0;
        }
        for(k=0; k<9; k++) {
          if(i==(i/3)*3+k/3&&j==(j/3)*3+k%3) continue;
          if(board[(i/3)*3+k/3][(j/3)*3+k%3]) candidate[board[(i/3)*3+k/3][(j/3)*3+k%3]-1] = 0;
        }
        blank--;
        for(k=0; k<9; k++) {
          if(candidate[k]) {
            board[i][j] = k+1;
            if(!blank) return;
            sudoku();
            if(!blank) return;
          }
        }
        if(blank) {
          blank++;
          board[i][j] = 0;
        }
        return;
      }
    }
  }
}

int main() {
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      scanf("%d", &board[i][j]);
      if(!board[i][j]) blank++;
    }
  }
  sudoku();
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}
