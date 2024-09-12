#include <iostream>
#include <vector>
using namespace std;
int v[1025][1025];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> v[i][j];
            v[i][j] += v[i][j-1];
        }
    }

    while (M--) {
        int x1,y1,x2,y2; cin >> y1 >> x1 >> y2 >> x2;
        int sum = 0;
        for (int i = y1; i <= y2; i++) {
            sum += v[i][x2] - v[i][x1-1];
        }
        cout << sum << '\n';
    }
}