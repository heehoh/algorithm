#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

void perm(vector<int> &arr, vector<int> ans, int dep) {
    if (dep == n) {
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 0; i < m; i++) {
        ans[dep] = arr[i];
        perm(arr, ans, dep + 1);
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
    perm(arr, ans, 0);
}