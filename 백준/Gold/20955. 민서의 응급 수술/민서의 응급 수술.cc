#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[100001];
vector<int> parent(100001, -1);

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

int is_diff(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (parent[a] == parent[b])
        --parent[a];
    if (parent[a] < parent[b])
        parent[b]= a;
    else
        parent[a] = b;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int cnt = 0;
    int edge = 0;
    for (int i = 1; i <= N; i++) {
        for (auto j : adj[i]) {
            if (!is_diff(i, j)) ++cnt;
            else ++edge;
        }
    }
    cnt += N - 1 - edge;
    cout << cnt;
}