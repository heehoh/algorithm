#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int map[8][8];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt = 0;
struct Point {
    int x;
    int y;
};

void BFS() {
    queue<Point> q;
    int tmp[8][8];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = map[i][j];
            if (tmp[i][j] == 2) {
                q.push({j, i});
            }
        }
    }
    while (!q.empty()) {
        Point p = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (x < 0 || x >= M || y < 0 || y >= N)
                continue;
            if (tmp[y][x] == 0) {
                tmp[y][x] = 2;
                q.push({x, y});
            }
        }
    }
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp[i][j] == 0) ++num;
        }
    }
    cnt = max(num, cnt);
}

void wall(int num) {
    if (num == 0) {
        BFS();
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                wall(num - 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    wall(3);
    cout << cnt;
}