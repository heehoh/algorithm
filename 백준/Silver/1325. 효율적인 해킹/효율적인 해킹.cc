#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> adj[10001];
vector<int> computer;
int trust;

void BFS(int st) {
    vector<bool> visited(N);
    queue<int> q;
    q.push(st);
    visited[st] = true;
    int num = 0;
    while (!q.empty()) {
        ++num;
        auto n = q.front(); q.pop();
        for (auto a : adj[n]) {
            if (visited[a] == true)
                continue;
            visited[a] = true;
            q.push(a);
        }
    }
    if (trust < num) {
        trust = num;
        computer.clear();
        computer.push_back(st);
    }
    else if (trust == num) {
        computer.push_back(st);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        BFS(i);
    }
    for (auto c : computer) {
        cout << c << ' ';
    }
}