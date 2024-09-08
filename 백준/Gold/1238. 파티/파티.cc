#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> adj[1001]; // X를 출발점으로 하는 노드
vector<pair<int, int>> reverse[1001]; // 역경로 X를 도착점으로 하는 각 노드의 최단 경로 구하는 용
const int INF = 1e9;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, x; cin >> N >> M >> x;
    vector<int> dist1(N+1, INF); // X 출발
    vector<int> dist2(N+1, INF);
    for (int i = 0; i < M; i++) {
        int a, b, cost; cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        reverse[b].push_back({cost, a});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist1[x] = 0;
    pq.push({dist1[x], x});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != dist1[cur.Y]) continue;
        for (auto nxt : adj[cur.Y]) {
            if (dist1[nxt.Y] <= dist1[cur.Y] + nxt.X) continue;
            dist1[nxt.Y] = dist1[cur.Y] + nxt.X;
            pq.push({dist1[nxt.Y], nxt.Y});
        }
    }
    
    dist2[x] = 0;
    pq.push({dist2[x], x});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != dist2[cur.Y]) continue;
        for (auto nxt : reverse[cur.Y]) {
            if (dist2[nxt.Y] <= dist2[cur.Y] + nxt.X) continue;
            dist2[nxt.Y] = dist2[cur.Y] + nxt.X;
            pq.push({dist2[nxt.Y], nxt.Y});
        }
    }
    
    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (max < dist1[i] + dist2[i])
            max = dist1[i] + dist2[i];
    }
    cout << max;
}