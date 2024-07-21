#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, K; 
int visited[100001];
int cnt[100001];
int dx[3] = {1, -1, 2};

void BFS() {
    queue<int> q;
    q.push(N);
    visited[N] = 0;
    cnt[N] = 1;
    
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if (x == K) {
            cout << visited[x] << "\n" << cnt[x]; 
            return;
        }
        for (int i = 0; i < 3; i++) {
            int pos = x + dx[i];
            if (i == 2) {
                pos = x * 2;
            }
            if (pos < 0 || pos > 100000)
                continue;
            if (visited[pos] == -1) {
                visited[pos] = visited[x] + 1;
                cnt[pos] = cnt[x];
                q.push(pos);
            } else if (visited[pos] == visited[x] + 1) {
                cnt[pos] += cnt[x];
            }
        }
    }
}

int main() {
    cin >> N >> K;
    memset(visited, -1, sizeof(visited));
    BFS();
}