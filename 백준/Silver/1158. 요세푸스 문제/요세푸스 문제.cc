#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    cout << "<";
    while (!q.empty()) {
        for (int i = 1; i < M; i++) {
            int num = q.front(); q.pop();
            q.push(num);
        }
        int num = q.front(); q.pop();
        cout << num;
        if (!q.empty()) {
            cout << ", ";
        }
    }
    cout << ">";
}