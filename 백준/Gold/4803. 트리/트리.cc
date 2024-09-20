#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_tree(vector<bool> &visited, vector<vector<int>> &adj, int n) {
    if (visited[n])
        return false;
    queue<int> q;
    q.push(n);
    visited[n] = true;
    vector<int> parent(visited.size() + 1, -1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int c : adj[x]) {
            if (visited[c]) {
                if (parent[x] == c)
                    continue;
                return false;
            }
            visited[c] = true;
            parent[c] = x;
            q.push(c);
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Case = 1;
    while (1) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        vector<vector<int>> adj(n+1);
        vector<bool> visited(n+1);
        while (m--) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (is_tree(visited, adj, i))
                ++t;
        }
        cout << "Case " << Case << ": ";
        if (t == 0) {
            cout << "No trees.\n";
        } else if (t == 1) {
            cout << "There is one tree.\n";
        } else if (t > 1) {
            cout << "A forest of " << t << " trees.\n";
        }
        ++Case;
    }
}