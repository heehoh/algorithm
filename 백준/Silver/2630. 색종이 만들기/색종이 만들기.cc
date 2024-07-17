#include <iostream>

using namespace std;

int paper[129][129];
int white, blue;

void cal(int x, int y, int k) {
    int color = paper[y][x];
    for (int i = y; i <= y + k - 1; i++) {
        for (int j = x; j <= x + k - 1; j++) {
            if (color != paper[i][j]) {
                cal(x, y, k/2);
                cal(x + k/2, y, k/2);
                cal(x, y + k/2, k/2);
                cal(x + k/2, y + k/2, k/2);
                return;
            }
        }
    }
    if (color == 0)
        ++white;
    else
        ++blue;
}

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> paper[i][j];
        }
    }
    cal(1, 1, N);
    cout << white << "\n" << blue;
}