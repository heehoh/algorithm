#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, K;

int getCost(vector<int> &cost, vector<int> adj[], vector<int>& deg) {
    int last; cin >> last;
    queue<int> q;
    vector<int> res = cost;

    for (int i = 1; i <= N; i++)
        if (deg[i] == 0) q.push(i);

    while (!q.empty()) {
        int n = q.size();
        int c = 0;
        while (n--) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (res[nxt] < res[cur] + cost[nxt])
                    res[nxt] = res[cur] + cost[nxt];
                deg[nxt]--;
                if (deg[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
    }
    return res[last];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> cost(N+1);
        vector<int> adj[1001];
        vector<int> deg(N+1);
        for (int i = 1; i <= N; i++)
            cin >> cost[i];
        for (int i = 0; i < K; i++) {
            int X, Y; cin >> X >> Y;
            adj[X].push_back(Y);
            deg[Y]++;
        }
        cout << getCost(cost, adj, deg) << "\n";
    }
}