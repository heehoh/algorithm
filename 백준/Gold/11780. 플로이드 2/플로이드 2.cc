#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int dist[101][101];
int route[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
            route[a][b] = b;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    route[i][j] = route[i][k];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            if (route[i][j] == 0) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while (st != j) {
                path.push_back(st);
                st = route[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (auto x: path) cout << x << ' ';
            cout << '\n';
        }
    }
}