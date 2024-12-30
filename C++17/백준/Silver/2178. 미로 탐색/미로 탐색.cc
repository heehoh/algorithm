#include <iostream>
#include <queue>
using namespace std;

struct Pos {
    int x;
    int y;
};

char map[101][101];
int visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;

void BFS() {
    queue<Pos> q;
    q.push({1, 1});
    visited[1][1] = 1;
    while (!q.empty()) {
        Pos p = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (x <= 0 || x > M || y <= 0 || y > N) continue;
            if (map[y][x] == '0' || visited[y][x] != 0) continue;
            visited[y][x] = visited[p.y][p.x] + 1;
            q.push({x, y});
        }
    }
    cout << visited[N][M];
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j-1];
        }
    }
    BFS();
}