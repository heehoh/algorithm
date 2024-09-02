#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> v[100][10001];
#define size first
#define idx second
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N; cin >> M >> N;
    int size = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> size;
            v[i][j] = {size, j};
        }
        sort(&v[i][0], &v[i][N]);
    }
    int ans = 0;
    for (int i = 0; i < M - 1; i++) {
        for (int j = i + 1; j < M; j++) {
            bool equal = true;
            for (int k = 0; k < N; k++) {
                if (v[i][k].idx != v[j][k].idx) {
                    equal = false;
                    break;
                } else {
                    if (k != N -1) {
                        if (v[i][k].size < v[i][k+1].size != v[j][k].size < v[j][k+1].size) {
                            equal = false;
                            break;
                        }
                    }
                }
            }
            if (equal) {
                ++ans;
            }
        }
    }
    cout << ans;
}