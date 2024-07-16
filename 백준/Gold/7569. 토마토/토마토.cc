#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int box[100][100][100];
int days[100][100][100] = {0, };

struct Point {
    int x;
    int y;
    int z;
};

void set() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
            }
        }
    }
}

int BFS() {
    queue<Point> q;
    int day = 0;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 1) {
                    q.push({k, j, i});
                }
            }
        }
    }
    
    while (!q.empty()) {
        Point p = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            int z = p.z + dz[i];
            if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= H)
                continue;
            if (box[z][y][x] != 0)
                continue;
            q.push({x, y, z});
            box[z][y][x] = 1;
            days[z][y][x] = days[p.z][p.y][p.x] + 1;
        }
    }
                
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0)
                    return -1;
                if (day < days[i][j][k])
                    day = days[i][j][k];
            }
        }
    }
    
    return day;
}

int main() {
    cin >> M >> N >> H;
    set();
    cout << BFS();
}