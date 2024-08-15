#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v,e,st;

vector<pair<int, int>> adj[20001];
const int INF = 1000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> e >> st;
    vector<int> dist(v+1, INF);
    
    // 인접리스트 값받기
    while (e--) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        
        // 거리가 dist에 있는 값과 다를 경우 넘어감
        if (dist[cur.second] != cur.first) continue;
        for (auto nxt : adj[cur.second]) {
            // 거리가 더 작을 때는 넘어감
            if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({dist[nxt.second], nxt.second});
        }
    }
    
    
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}