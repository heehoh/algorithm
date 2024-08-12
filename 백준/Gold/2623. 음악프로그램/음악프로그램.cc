#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;
vector<int> adj[1001];
int indegree[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while (M--) {
        int num; cin >> num;
        int prev = 0;
        for (int i = 0; i < num; i++) {
            int t; cin >> t;
            if (prev == 0) {
                prev = t;
                continue;
            }
            adj[prev].push_back(t);
            indegree[t]++;
            prev = t;
        }
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= N; i++) 
        if (indegree[i] == 0) q.push(i);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
    
        for (int nxt : adj[cur]) {
            --indegree[nxt];
            if (indegree[nxt] == 0) q.push(nxt);
        }
    }
    if (ans.size() != N)
        cout << 0;
    else {
        for (auto x : ans) {
            cout << x << '\n';
        }
    }
}