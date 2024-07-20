#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int pos;
    int num;
};

int map[100];
bool visited[100];

void BFS() {
    int n = 0;
    queue<Point> q;
    q.push({1, 0});
    visited[0] = true;
    
    while (1) {
        Point p = q.front(); q.pop();

        for (int i = 1; i <= 6;i++){
            int nx = p.pos + i; // 다음 좌표
            if(nx == 100){
                cout << p.num +1; // 도착했으면 출력
                return;
            }
            else if(nx < 100){ // 100보다 작은 좌표라면 
                while(map[nx] != 0){ // 사다리 혹은 뱀인지 확인
                    nx = map[nx]; // 점프한 자리로 이동
                }
                if(!visited[nx]){ // 처음 방문한 좌표일때
                    q.push({nx, p.num + 1}); // 큐에 넣어줌
                    visited[nx] = true; // 방문처리
                }
                
            }
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    
    while (N--) {
        int x, y; cin >> x >> y;
        map[x] = y;
    }
    
    while (M--) {
        int x, y; cin >> x >> y;
        map[x] = y;
    }
    
    BFS();
}