#include <stdio.h>
#include <string.h>

char map[5][6]; // map info
int dp_table[5][5][10]; // dp table

const int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};//moving directions
int boggle(char word[11], int x, int y, int index) {
    int ret = 0;
    int i;
    if(!word[index])
        return 1;
    if(dp_table[x][y][index] != -1)
        return dp_table[x][y][index];
    if(word[index] == map[x][y]) {
        for(i=0; i<8; i++) {
            if(x+dx[i] < 0 || x+dx[i] > 4 || y+dy[i] < 0 || y+dy[i] > 4)
                continue;
            if(boggle(word, x+dx[i], y+dy[i], index + 1)) {
                ret = 1;
                break;
            }
        }
    }
    dp_table[x][y][index] = ret;
    return ret;
}

int main() {
    int c, w; // test case, number of words
    int i, j, x, y; // for loop index
    int result;
    char word[11]; // word
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        for(j=0; j<5; j++) {
            scanf("%s", map[j]);
        }
        scanf("%d", &w);
        for(j=0; j<w; j++) {
            memset(dp_table, -1, 250 * sizeof(int));
            scanf("%s", word);
            result = 0;
            for(x=0; x<5; x++) {
                for(y=0; y<5; y++) {
                    if(boggle(word, x, y, 0)) {
                        result = 1;
                        break;
                    }
                }
                if(result)
                    break;
            }
            printf("%s %s\n", word, result ? "YES" : "NO");
        }
    }
    return 0;
}
