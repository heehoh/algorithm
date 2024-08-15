#include <iostream>
#include <queue>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            pq.push(a);
            if (pq.size() > N)
                pq.pop();
        }
    }
    cout << pq.top();
}