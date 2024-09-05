#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int node, edge; cin >> node >> edge;        
        vector<vector<int>> adj(node + 1);
        vector<bool> check(node + 1, false);
        int a, b;
        for (int i = 0; i < edge; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int res = 0;
        queue<int> q;
        q.push(1);
        check[1] = true;
        
        while (!q.empty()) {
            int idx = q.front(); q.pop();
            for (int nxt : adj[idx]) {
                if (!check[nxt]) {
                    check[nxt] = true;
                    res++;
                    q.push(nxt);
                }
            }
        }
        cout << res << '\n';
    }
}