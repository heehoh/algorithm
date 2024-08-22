#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    deque<pair<int, int>> dq; // 값, 인덱스
    int N, L; cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;

        if (!dq.empty() && dq.front().second <= i - L) {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first > a) {
            dq.pop_back();
        }

        dq.push_back({a, i});
        cout << dq.front().first << " ";
    }
}