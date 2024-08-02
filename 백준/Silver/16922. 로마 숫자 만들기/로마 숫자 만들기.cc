#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int d[4] = {1, 5, 10, 50};
int ans;
bool visited[21][1001]; // 방문 여부를 체크하는 배열

void recur(int n, int num) {
    if (n == 0) {
        if (!visited[n][num]) {
            ++ans;
            visited[n][num] = true;
        }
        return;
    }
    if (visited[n][num]) return; // 이미 방문한 조합이면 리턴
    visited[n][num] = true; // 현재 조합을 방문 처리

    for (int i = 0; i < 4; i++) {
        recur(n - 1, num + d[i]);
    }
}

int main() {
    int n; cin >> n;
    recur(n, 0);
    cout << ans;
    return 0;
}