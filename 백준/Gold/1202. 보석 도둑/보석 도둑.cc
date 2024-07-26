#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Stone {
    int w;
    int v;
};
bool cmp(const Stone& a, const Stone &b) {
    return a.v > b.v;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<Stone> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].w >> v[i].v;
    }
    sort(v.begin(), v.end(), cmp);
    multiset<int> s;
    for (int i = 0; i < K; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        auto it = s.lower_bound(v[i].w);
        if (*it == v[i].w) {
            s.erase(it);
            sum += v[i].v;
        } else {
            it = s.upper_bound(v[i].w);
            if (it == s.end())
                continue;
            s.erase(it);
            sum += v[i].v;
        }
    }
    cout << sum;
}