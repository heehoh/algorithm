#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[600][600];
bool visit[600][600];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Point {
    int x;
    int y;
};

void BFS() {
    queue<Point> q;
    int meet = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') {
                q.push({j, i});
            }
        }
    }
    
    while (!q.empty()) {
        Point p = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            
            if (x < 0 || x >= N || y < 0 || y >= M || visit[y][x] || map[y][x] == 'X')
                continue;
            if (map[y][x] == 'P') {
                ++meet;
            }
            visit[y][x] = true;
            q.push({x, y});
        }
    }
        
    if (meet)
        cout << meet;
    else
        cout << "TT";
}

int main() {
    cin >> M >> N;
    BFS();
}