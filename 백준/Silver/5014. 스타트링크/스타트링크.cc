#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int visited[1000001];
int F, S, G, U, D;
int dx[2];

void BFS() {
    queue<int> q; q.push(S);
    visited[S] = 1;
    
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            if (nx < 1 || nx > F || visited[nx] != 0) continue;
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;
    dx[0] = U;
    dx[1] = -D;
    BFS();
    if (visited[G] == 0)
        cout << "use the stairs";
    else
        cout << visited[G] - 1;
}