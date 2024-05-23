#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long profit = 0;
        long long sell_val = v[n - 1];
        int sell_idx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (sell_val < v[i]) {
                for (int idx = i + 1; idx < sell_idx; idx++) {
                    profit += sell_val - v[idx];
                }
                sell_val = v[i];
                sell_idx = i;
            }
        }
        for (int i = 0; i < sell_idx; i++) {
            profit += sell_val - v[i];
        }
        cout << profit << '\n';
    }
}