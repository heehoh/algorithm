#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[20][20];
struct Point {
    int x;
    int y;
};
Point shark;
bool eat = true;
int sizes = 2;
int grow = 0;
int times = 0;
int N;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void BFS() {
    int visited[20][20];
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            visited[i][j] = -1;

    queue<Point> q;
    q.push(shark);
    visited[shark.y][shark.x] = 0;
    Point target = {-1, -1};
    int minDist = 400; // 큰 값으로 초기화

    while (!q.empty()) {
        Point p = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int x = p.x + dx[i];
            int y = p.y + dy[i];
            if (x < 0 || x >= N || y < 0 || y >= N) continue;
            if (sizes < map[y][x] || visited[y][x] != -1) continue;
            visited[y][x] = visited[p.y][p.x] + 1;
            if (sizes > map[y][x] && map[y][x] != 0) {
                if (visited[y][x] < minDist || 
                   (visited[y][x] == minDist && (y < target.y || (y == target.y && x < target.x)))) {
                    minDist = visited[y][x];
                    target = {x, y};
                }
            }
            q.push({x, y});
        }
    }
    if (target.x != -1) {
        times += minDist;
        shark = target;
        map[shark.y][shark.x] = 0;
        ++grow;
        if (grow == sizes) {
            grow = 0;
            ++sizes;
        }
        eat = true;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark.x = j; shark.y = i;
                map[i][j] = 0;
            }
        }
    }
    while (eat) {
        eat = false;
        BFS();
    }
    cout << times;
}