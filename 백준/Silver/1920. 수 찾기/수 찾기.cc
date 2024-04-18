#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int binarysearch(int target, vector<int>& v) {
    int st = 0;
    int en = n - 1;
    while (st <= en) {
        int mid = (st+en)/2;
        if (v[mid] < target)
            st = mid+1;
        else if (v[mid] > target)
            en = mid -1;
        else
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        cout << binarysearch(t, v) << '\n';
    }
}