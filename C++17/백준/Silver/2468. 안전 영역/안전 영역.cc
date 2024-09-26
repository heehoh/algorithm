#include <iostream>
#include <queue>
using namespace std;
int map[100][100];
bool visited[100][100];
int N;
int ans = 1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
#define X first
#define Y second

void BFS(int x, int y, int h) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nxtX = cur.X + dx[i];
            int nxtY = cur.Y + dy[i];
            if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N) continue;
            if (map[nxtY][nxtX] > h && !visited[nxtY][nxtX]) {
                visited[nxtY][nxtX] = true;
                q.push({nxtX, nxtY});
            }
        }
    }
}

void countArea(int h) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] > h && !visited[i][j]) {
                BFS(j, i, h);
                ++num;
            }
        }
    }
    if (num > ans)
        ans = num;
}

int main() {
    cin >> N;
    vector<vector<int>> v(N);
    int mxH = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (mxH < map[i][j])
                mxH = map[i][j];
        }
    }
    for (int i = 1; i < mxH; i++) {
        countArea(i);
    }
    cout << ans;
}