#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

vector<int> arr;
vector<bool> check1;
vector<int> ans;

void comb(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
      if (!check1[i] && x != arr[i]) {
        ans[dep] = arr[i];
        x = arr[i];
        check1[i] = true;
        comb(dep + 1);
        check1[i] = false;
      }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    check1.resize(n);
    ans.resize(m);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    comb(0);
}