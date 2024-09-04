#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[10001];
int deg[10001];
int time1[10001];
int total[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        time1[i] = t;
        int n; cin >> n;
        deg[i] = n;
        while (n--) {
            int a; cin >> a;
            adj[a].push_back(i);
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            q.push(i);
            total[i] = time1[i];
        }
    }
    
    while (!q.empty()) {
        int n = q.front(); q.pop();
        for (auto a : adj[n]) {
            --deg[a];
            if (total[a] < total[n] + time1[a])
                total[a] = total[n] + time1[a];
            if (deg[a] == 0) {
                q.push(a);
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= N; i++) {
        if (mx < total[i]) {
            mx = total[i];
        }
    }
    cout << mx;
}