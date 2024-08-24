#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[1001];
const int INF = 2147483647;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> d(n+1, INF);
    vector<int> pre(n+1);
    while (m--) {
        int st, en, cost; cin >> st >> en >> cost;
        adj[st].push_back({cost, en});
    }
    
    int st, en; cin >> st >> en;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        } 
    }
    cout << d[en] << "\n";
    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (auto x : path) cout << x << ' ';
}