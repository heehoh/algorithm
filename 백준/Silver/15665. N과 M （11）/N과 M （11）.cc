#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;

void perm(int dep) {
    if (dep == m) {
        for (auto v: ans) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (x == arr[i]) continue;
        ans[dep] = arr[i];
        x = arr[i];
        perm(dep + 1);
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    ans.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    perm(0);
}