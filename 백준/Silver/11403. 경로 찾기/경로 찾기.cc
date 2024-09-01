#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[101];
int route[101][101];
int N;

void BFS(int st) {
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto i : adj[cur]) {
            if (route[st][i] == 1)
                continue;
            route[st][i] = 1;
            q.push(i);
        }
    }
}

int main() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num; cin >> num;
            if (num == 1)
                adj[i].push_back(j);
        }
    }
    
    for (int i = 1; i <= N; i++)
        BFS(i);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << route[i][j] << ' ';
        }
        cout << '\n';
    }
}