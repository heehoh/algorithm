#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> v[32001];
int deg[32001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        ++deg[b];
        v[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        cout << p << ' ';
        for (int a : v[p]) {
            --deg[a];
            if (deg[a] == 0) {
                q.push(a);
            }
        }
    }
}