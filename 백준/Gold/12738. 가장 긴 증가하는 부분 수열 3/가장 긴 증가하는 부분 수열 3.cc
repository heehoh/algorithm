#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    vector<int> l;
    for (auto num : v) {
        auto it = lower_bound(l.begin(), l.end(), num);
        if (it == l.end()) {
            l.push_back(num);
        } else {
            *it = num;
        }
    }
    
    cout << l.size();
}