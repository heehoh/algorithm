#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> adj[200001];
int N;

void bfs(vector<int> &visited) {
    queue<int> q;
    
    visited[1] = true;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = visited[cur] + 1;
            q.push(nxt);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> C(N+1);
    vector<int> visited(N+1);
    
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    bfs(visited);
    vector<int> arr;
    for (int i = 1; i <= N; i++) {
        if (C[i]) arr.push_back(visited[i]);
    }
    
    sort(arr.rbegin(), arr.rend());
    int t = 0, mx = 0;
    for (auto i: arr) {
        mx = max(mx, i+t);
        ++t;
    }
    cout << mx; 
    
}