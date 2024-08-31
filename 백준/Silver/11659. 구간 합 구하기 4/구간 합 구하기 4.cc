#include <iostream>
#include <vector>
using namespace std;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    vector<int> v(N+1);
    vector<int> sum(N+1);
    
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        sum[i] = v[i]; 
        if (i > 1) {
            sum[i] += sum[i-1];
        }
    }
    while (M--) {
        int i, j; cin >> i >> j;
        cout << sum[j] - sum[i] + v[i] << "\n";
    }    
}