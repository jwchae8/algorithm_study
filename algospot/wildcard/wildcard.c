#include<stdio.h>
#include<string.h>

int dp_table[101][101];

int wildcard(char regex[101], char word[101], int r, int w) {
    int i;
    if(dp_table[r][w] != -1)
        return dp_table[r][w];

    while(r < strlen(regex) && w < strlen(word) && (regex[r] == '?' || regex[r] == word[w])) {
        r++; w++;
    }

    if(r == strlen(regex)) {
        return w == strlen(word);
    }

    if(regex[r] == '*') {
        for(i=0; i<=strlen(word)-w; i++) {
            if((dp_table[r][w] = wildcard(regex, word, r+1, w+i)) == 1)
                return 1;
        }
    }
    dp_table[r][w] = 0;
    return 0;
}

int main() {
    int c, w; // test case, number of words
    char regex[101], word[101]; // pattern, input
    char answerlist[50][101];
    int cnt;
    int i, j, k, l; // for loop index
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        scanf("%s", regex);
        scanf("%d", &w);
        cnt = 0;
        for(j=0; j<w; j++) {
            scanf("%s", word);
            memset(dp_table, -1, sizeof(int) * 101 * 101);
            if(wildcard(regex, word, 0, 0)) {
                if(cnt == 0) {
                    strcpy(answerlist[0], word);
                    cnt++;
                }
                else {
                    int flag = 0;
                    for(k=0; k<cnt; k++) {
                        int x = 0, y = 0;
                        while(x < strlen(answerlist[k]) && y < strlen(word)) {
                            if(answerlist[k][x] > word[y]) {
                                flag = 1;
                                break;
                            }
                            else if(answerlist[k][x] < word[y]) {
                                break;
                            }
                            else {
                                x++; y++;
                            }
                        }
                        if(flag)
                            break;
                    }
                    for(l = cnt; l > k; l--) {
                        strcpy(answerlist[l], answerlist[l - 1]);
                    }
                    strcpy(answerlist[k], word);
                    cnt++;
                }
            }
        }
        for(j=0; j<cnt; j++) {
            printf("%s\n", answerlist[j]);
        }
    }
    return 0;
}

/*
 * *as*as
 * #asdfasdf
 */
