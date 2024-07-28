#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int v[1001][1001];
bool visited[1001];
int num;

void BFS(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
  
    while (!q.empty()) {
        int pos = q.front(); q.pop();
        for (int i = 1; i <= N; i++) {
            if (v[pos][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M; 
    while (M--) {
        int x, y; cin >> x >> y;
        v[x][y] = 1;
        v[y][x] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            BFS(i);
            ++num;
        }
    }
    cout << num;
}