#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

void comb(vector<int> &arr, vector<int> &ans, int dep, int next) {
    if (n == dep) {
        for (auto v: ans) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = next; i < m; i++) {
        ans[dep] = arr[i];
        comb(arr, ans, dep + 1, i);
    }
}

int main() {
    cin >> m >> n;
    vector<int> arr(m);
    vector<int> ans(n);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    comb(arr, ans, 0, 0);
}