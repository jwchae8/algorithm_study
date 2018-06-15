#include <stdio.h>

int friend_match(int friends[10][10], int visited[], int n, int matched) {
    int ret = 0;
    int i, j;
    if(matched == n) return 1;
    for(i=0; i<n; i++){
        if(visited[i]) continue;
        for(j=i+1; j<n; j++){
            if(!visited[j] && friends[i][j]) {
                visited[i] = 1;
                visited[j] = 1;
                ret += friend_match(friends, visited, n, matched+2);
                visited[i] = 0;
                visited[j] = 0;
            }
        }
        break;
    }
    return ret;
}

int main() {
    int friends[10][10]; // friendship information
    int visited[10]; // is friend being matched?
    int c, n, m; // test case, number of people, number of friendship
    int i, j, k; // for loop index
    int a, b; // friendship input
    scanf("%d", &c);
    for(i=0; i<c; i++) {
        for(j=0; j<10; j++) {
            visited[j] = 0;
            for(k=0; k<10; k++) {
                friends[j][k] = 0;
            }
        }
        scanf("%d %d", &n, &m);
        for(j=0; j<m; j++) {
            scanf("%d %d", &a, &b);
            if(a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            friends[a][b] = 1;
        }
        printf("%d\n", friend_match(friends, visited, n, 0));
    }
}
