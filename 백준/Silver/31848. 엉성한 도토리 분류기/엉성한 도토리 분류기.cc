#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int where[200002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> hole(N);
    for (int i = 0; i < N; i++) {
        cin >> hole[i];
        hole[i] += i;
    }
    for (int i = N - 1; i >= 0; i--) {
        where[hole[i]] = i + 1;
    }

    int min = N;
    for (int i = 200002; i >= 1; --i) {
        if (where[i] && where[i] < min)
            min = where[i];
        where[i] = min;
    }
    
    sort(hole.begin(), hole.end());
    int Q; cin >> Q;
    vector<int> dotori(Q);
    for (int i = 0; i < Q; i++) {
        cin >> dotori[i];
    }

    vector<int> ans(Q);
    for (int i = 0; i < Q; i++) {
        auto it = lower_bound(hole.begin(), hole.end(), dotori[i]);
        ans[i] = where[*it];
    }
    for (auto a : ans) {
        cout << a  << ' ';
    }
}