#include <iostream>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    set<int> a, b, c;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num; a.insert(num);
    }
    for (int i = 0; i < m; i++) {
        cin >> num; b.insert(num);
    }
    for (auto x : a) {
        if (b.find(x) == b.end()) {
            c.insert(x);
        }
    }
    cout << c.size() << '\n';
    for (auto x : c) {
        cout << x << ' ';
    }
}