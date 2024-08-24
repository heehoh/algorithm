#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;
int n;
int dist[16][16];
int dp[1 << 16][16];

int tsp(int visited, int cur) {
    if (visited == (1 << n) - 1) {
        return dist[cur][0] == 0 ? INF : dist[cur][0];
    }
    if (dp[visited][cur] != -1)
        return dp[visited][cur];
    
    dp[visited][cur] = INF;
    
    for (int nxt = 0; nxt < n; nxt++) {
        if (visited & (1 << nxt)) continue;
        if (dist[cur][nxt] == 0) continue;
        dp[visited][cur] = min(dp[visited][cur], tsp(visited | (1 << nxt), nxt) + dist[cur][nxt]);
    }
    
    return dp[visited][cur];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << tsp(1, 0);
}