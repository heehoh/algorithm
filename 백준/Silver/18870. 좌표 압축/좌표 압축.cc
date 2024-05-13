#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < n; i++) {
        cout << lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin() << " ";
    }
    return 0;
}