#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int pos;
    int num;
};

int map[100];
bool visited[100];

int BFS() {
    int n = 0;
    queue<Point> q;
    q.push({1, 0});
    visited[1] = true;
    
    while (1) {
        Point p = q.front(); q.pop();

        if (p.pos == 100)
            return p.num;
        for (int i = 1; i <= 6; i++) {
            int pos = p.pos + i;
            if (pos == 100) {
                return p.num + 1;
            }
            while (map[pos])
                pos = map[pos];
            if (visited[pos])
                continue;
            visited[pos] = true;
            q.push({pos, p.num + 1});
        }
    }
    return 0;
}

int main() {
    int N, M; cin >> N >> M;
    
    while (N--) {
        int x, y; cin >> x >> y;
        map[x] = y;
    }
    
    while (M--) {
        int x, y; cin >> x >> y;
        map[x] = y;
    }
    
    cout << BFS();
}