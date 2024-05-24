#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

#define X first
#define Y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[50][50];
int M, N, K;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    map[y][x] = 0;
    q.push({x, y});

    while (!q.empty()) {
        auto tmp = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tmp.X + dx[i];
            int ny = tmp.Y + dy[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (map[ny][nx] == 0) continue;
            map[ny][nx] = 0;
            q.push({nx, ny});
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        memset(map, 0, sizeof(map));
        while (K--) {
            int x, y; cin >> x >> y;
            map[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) {
                    ++cnt;
                    bfs(j, i);
                }
            }
        }
        cout << cnt << '\n';
    }
}