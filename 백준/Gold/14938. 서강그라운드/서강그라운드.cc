#include <iostream>
#include <cstring>

using namespace std;

int map[101][101];
int items[101];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, r; cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = INF;
        }
    }

    
    while (r--) {
        int x, y, cost;
        cin >> x >> y >> cost;
        map[x][y] = cost;
        map[y][x] = cost;
    }
    
    for (int i =1; i <= n; i++) {
        map[i][i] = 0;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    
    int max = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (map[i][j] <= m) {
                tmp += items[j];
            }
        }
        if (tmp > max)
            max = tmp;
    }
    cout << max;
}