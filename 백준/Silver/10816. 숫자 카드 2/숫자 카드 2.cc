#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lower_bound(int target, vector<int> &v) {
    int st = 0, en = v.size();
    while (st < en) {
        int mid = (st + en)/2;
        if (v[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int upper_bound(int target, vector<int> &v) {
    int st = 0, en = v.size();
    while (st < en) {
        int mid = (st + en)/2;
        if (v[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int target; cin >> target;
        cout << upper_bound(target, v) - lower_bound(target, v) << " ";
    }
}