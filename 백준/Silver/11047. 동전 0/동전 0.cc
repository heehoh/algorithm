#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    int* A = new int[N];
    for (int i; i < N; ++i) {
        cin >> A[i]; 
    }
    int cnt = 0;
    int i = N - 1;
    while (K) {
        while (K - A[i] >= 0) {
            K -= A[i];
            ++cnt;
        }
        --i;
    }
    cout << cnt << '\n';
}