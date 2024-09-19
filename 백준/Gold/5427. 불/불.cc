#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001
#define X first
#define Y second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char building[MAX][MAX];
int fire[MAX][MAX];
int person[MAX][MAX];

void fill_num(int m[MAX][MAX]) {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            m[i][j] = -1;
        }
    }
}

void BFS(int w, int h) {
    fill_num(fire);
    fill_num(person);

    queue<pair<int, int>> fq;
    queue<pair<int, int>> pq;
    for (int i = 1; i <= h; i++) {
        string s; cin >> s;
        for (int j = 1; j <= w; j++) {
            building[i][j] = s[j-1];
            if (building[i][j] == '*') {
                fq.push({j, i});
                fire[i][j] = 0;
            } else if (building[i][j] == '@') {
                pq.push({j, i});
                person[i][j] = 0;
            }
        }
    }

    while (!pq.empty() || !fq.empty()) {
        int n = fq.size();
        while (n--) {
            auto cur = fq.front(); fq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx <= 0 || nx > w || ny <= 0 || ny > h) continue;
                if (fire[ny][nx] != -1 || building[ny][nx] == '#') continue;
                fq.push({nx, ny});
                fire[ny][nx] = fire[cur.Y][cur.X] + 1;
            }
        }
        n = pq.size();
        while (n--) {
            auto cur = pq.front(); pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx <= 0 || nx > w || ny <= 0 || ny > h) {
                    cout << person[cur.Y][cur.X] + 1 << '\n';
                    return;
                }
                if (fire[ny][nx] != -1 || person[ny][nx] != -1 || building[ny][nx] == '#') continue;
                pq.push({nx, ny});
                person[ny][nx] = person[cur.Y][cur.X] + 1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) { 
        int w, h; cin >> w >> h;
        BFS(w, h);
    }
}