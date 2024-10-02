#include <iostream>
#include <queue>
using namespace std;
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        vector<vector<int>> visited(N, vector<int>(N, -1));
        queue<pair<int, int>> q;
        q.push({x1, y1});
        visited[y1][x1] = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.X == x2 && cur.Y == y2) {
                cout << visited[cur.Y][cur.X] << '\n';
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (visited[ny][nx] != -1) continue;
                visited[ny][nx] = visited[cur.Y][cur.X] + 1;
                q.push({nx, ny});
            }
        }
    }
}