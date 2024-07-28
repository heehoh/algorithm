#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> v[100001];
bool visited[100001];
int parent[100001];
void BFS() {
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        for (int x : v[p]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                parent[x] = p;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
}