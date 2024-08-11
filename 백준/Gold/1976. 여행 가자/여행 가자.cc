#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> road[201];
int n;

int check(int st, int en) {
    vector<bool> visited(n);
    visited[st] = true;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == en)
            return 0;
        for (auto n : road[x]) {
            if (visited[n] == false) {
                q.push(n);
                visited[n] = true;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> n >> m;
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x == 1) {
                road[i].push_back(j);
            }
        }
    }
    vector<int> route(m);
    for (int i = 0; i < m; i++) {
        cin >> route[i];
    }
    for (int i = 0; i < m - 1; i++) {
        if (check(route[i], route[i+1])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}