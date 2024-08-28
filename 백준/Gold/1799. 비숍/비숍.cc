#include <iostream>
using namespace std;
int N;
int board[10][10];

int mx[2];
int visited1[20];
int visited2[20];

void recur(int cnt, int x, int y, int color) {
    if (x >= N) {
        y++;
        if (x % 2 == 0) x = 1;
        else x = 0;
    }
    if (y >= N) {
        if (cnt > mx[color])
            mx[color] = cnt;
        return;
    }
 
    if (board[y][x] && !visited1[x + y + 1] && !visited2[x - y + N]) {
        visited1[x + y + 1] = true;
        visited2[x - y + N] = true;
        recur(cnt + 1, x + 2, y, color);
        visited1[x + y + 1] = false;
        visited2[x - y + N] = false;
    }
    recur(cnt, x + 2, y, color);
}
 
int main(void) {
    cin >> N;
 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    recur(0, 0, 0, 0);
    recur(0, 1, 0, 1);
 
    cout << mx[0] + mx[1] << '\n';
}