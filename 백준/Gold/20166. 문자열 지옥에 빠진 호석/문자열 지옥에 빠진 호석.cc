#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int N, M, K;
int num;
char map[11][11];
int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
unordered_map<string, int> m;

void dfs(string &s, int dep, int x, int y) {
    if (dep == s.length()) {
        m[s]++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];
        if (cur_x == 0)
            cur_x = M;
        else if (cur_x == M + 1)
            cur_x = 1;
        if (cur_y == 0)
            cur_y = N;
        else if (cur_y == N + 1)
            cur_y = 1;
        if (map[cur_y][cur_x] == s[dep])
            dfs(s,dep+1,cur_x,cur_y);
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= M; j++) {
            map[i][j] = s[j - 1];
        }
    }
    while (K--) {
        string s; cin >> s;
        if (m.find(s) == m.end()) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (map[i][j] == s[0]) {
                        dfs(s, 1, j, i);
                    }
                }
            }
        }
        cout << m[s] << "\n";
    }
}