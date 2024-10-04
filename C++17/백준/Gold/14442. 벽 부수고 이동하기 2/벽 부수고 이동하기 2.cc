#include <iostream>
#include <queue>
using namespace std;
int visited[11][1001][1001];
int map[1001][1001];
int wall[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M, K;

struct Pos {
    int k;
    int x;
    int y;
};

void BFS() {
    queue<Pos> q;
    
    q.push({0, 1, 1});
    visited[0][1][1] = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur.x == M && cur.y == N) {
            cout << visited[cur.k][cur.y][cur.x];
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx <= 0 || nx > M || ny <= 0 || ny > N) continue;
            if (map[ny][nx] == 1 && cur.k < K && visited[cur.k + 1][ny][nx] == 0) {
                q.push({cur.k + 1, nx, ny});
                visited[cur.k + 1][ny][nx] = visited[cur.k][cur.y][cur.x] + 1;
            } else if (map[ny][nx] == 0 && visited[cur.k][ny][nx] == 0) {
                q.push({cur.k, nx, ny});
                visited[cur.k][ny][nx] = visited[cur.k][cur.y][cur.x] + 1;
             }
        }
    }
    cout << -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j-1] - '0';
        }
    }
    BFS();
    
}