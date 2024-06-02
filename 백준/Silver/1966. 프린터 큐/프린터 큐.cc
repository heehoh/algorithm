#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int get_max(deque<pair<int, int>> &q) {
    int max = 0;
    for (auto it : q) {
        if (max < it.first)
            max = it.first;
    }
    return max;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        deque<pair<int, int>> q;
        int max = 0;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            if (max < num)
                max = num;
            q.push_back({num, i});
        }
        int order = 1; 
        while (!q.empty()) {
            auto it = q.front();
            if (it.first == max) {
                q.pop_front();
                if (it.second == m) {
                    cout << order << '\n';
                    break;
                }
                max = get_max(q);
                ++order;
            }
            else {
                q.pop_front();
                q.push_back(it);
            }
        }
    }
}