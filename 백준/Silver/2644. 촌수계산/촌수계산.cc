#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[101][101];
int visited[101];

void bfs(int k) {
    queue<int> q;
    
    q.push(k);
    while(!q.empty()) {
        k = q.front(); q.pop();
        for (int i =1; i <=n; i++) {
            if (arr[k][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[k]+1;
            }
        }
    }
}

int main() {
    cin >> n;
    int a, b; cin >> a >> b;
    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
    bfs(a);
    if (visited[b] == 0) {
        visited[b] = -1;
    }
    cout << visited[b];
    
}