#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
char map[1001][1001];
int visited[2][1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct Point {
    int x;
    int y;
    bool breakWall;
};

void BFS() {
    queue<Point> q;
    q.push({1, 1, false});
    visited[0][1][1] = 1;
    while (!q.empty()) {
        Point p = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (y < 1 || y > N || x < 1 || x > M)
                continue;
            if (map[y][x] == '1' && p.breakWall == true)
                continue;
            if (p.breakWall && visited[1][y][x] == -1) {
                visited[1][y][x] = visited[1][p.y][p.x] + 1;
                if (x == M && y == N && visited[0][N][M] == -1)
                    visited[0][N][M] = visited[1][N][M];
                q.push({x, y, true});
            } else if (!p.breakWall && visited[0][y][x] == -1) {
                if (map[y][x] == '1') {
                    visited[1][y][x] = visited[0][p.y][p.x] + 1;
                    q.push({x, y, true});
                } else {
                    visited[0][y][x] = visited[0][p.y][p.x] + 1;
                    q.push({x, y, false});
                }
            }
        }
    }
    cout << visited[0][N][M];
}

int main() {
    cin >> N >> M;
    memset(visited, -1, sizeof(visited));
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j-1];
        }
    }
    BFS();
}