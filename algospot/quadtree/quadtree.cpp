#include <iostream>
#include <string>

using namespace std;

string quadtree(string board, int *pos) {
    char cur = board[*pos];
    string a, b, c, d;
    *pos = *pos + 1;
    if(cur == 'w')
        return string("w");
    else if(cur == 'b')
        return string("b");
    a = quadtree(board, pos);
    b = quadtree(board, pos);
    c = quadtree(board, pos);
    d = quadtree(board, pos);
    return string("x") + c + d + a + b;
}
int main() {
    string board;
    int c;
    int i;
    int pos;
    cin >> c;
    for(i=0; i<c; i++) {
        cin >> board;
        pos = 0;
        cout << quadtree(board, &pos) << "\n";
    }
    return 0;
}
