#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M, N;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int low = 1;
    int high = v[N-1];
    int maxLen = 0;
    while (low <= high) {
        int mid = (low + high) / 2; // 과자의 길이
        int cookie = 0; // 과자 수
        for (int i = 0; i < N; i++) {
            cookie += v[i] / mid;
        }
        if (M > cookie) {
            high = mid - 1;
        } else {
            maxLen = mid;
            low = mid + 1;
        }
    }
    cout << maxLen;
}