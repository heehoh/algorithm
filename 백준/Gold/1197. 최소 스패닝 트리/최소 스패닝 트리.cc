#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector<int> parent(10001, -1);
int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

int is_diffrent_group(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return 0;
    if (parent[a] == parent[b])
        --parent[a];
    if (parent[a] < parent[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E; cin >> V >> E;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < E; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge.push_back({cost, a, b});
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < E; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if (!is_diffrent_group(a, b)) continue;
        ans += cost;
        ++cnt;
        if (cnt == V-1) break;
    }
    cout << ans;
}