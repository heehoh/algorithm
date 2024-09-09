#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    cin >> M;
    
    sort(v.begin(), v.end());
    int st = 0;
    int en = v[N-1];
    int res, sum;
    
    while (st <= en) {
        sum = 0;
        int mid = (st+en)/2;
        for (int i = 0; i < N; i++) {
            sum += min(v[i], mid);
        }
        if (M >= sum) {
            res = mid;
            st = mid+1;
        } else {
            en = mid -1;
        }
    }
    cout << res;
}