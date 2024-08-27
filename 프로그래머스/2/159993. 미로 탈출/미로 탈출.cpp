#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define X first
#define Y second
int times[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int target_x, target_y;

int BFS(vector<string> &maps, int x, int y, char target) {
    queue<pair<int, int>> q;
    q.push({x, y});
    times[y][x] = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (maps[cur.Y][cur.X] == target) {
            target_x = cur.X; target_y = cur.Y;
            return times[cur.Y][cur.X];
        }

        for (int i = 0; i < 4; i++) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if (y < 0 || y > maps.size() - 1 || x < 0 || x > maps[y].length() - 1 || times[y][x] != -1) continue;
            if (maps[y][x] == 'X') continue;
            times[y][x] = times[cur.Y][cur.X] + 1;
            q.push({x, y});
        }

    }
    
    return -1;
} 


int solution(vector<string> maps) {
    int ans1 = 0;
    int ans2 = 0;
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] == 'S') {
                memset(times, -1, sizeof(times));
                ans1 = BFS(maps, j, i, 'L');
                if (ans1 == -1)
                    return -1;
                memset(times, -1, sizeof(times));
                ans2 = BFS(maps, target_x, target_y, 'E');
                if (ans2 == -1)
                    return -1;
                return ans1 + ans2;
            }
        }
    }
    
    return -1;
}