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
    sort(v.begin(), v.end());
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int target; cin >> target;
        cout << upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target) << " ";
    }
}