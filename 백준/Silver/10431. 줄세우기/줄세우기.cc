#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int v[20];
        int num = 0;
        for (int i = 0; i < 20; i++) {
            cin >> v[i];
            for (int j = 0; j < i; j++) {
                if (v[j] > v[i]) {
                    int tmp = v[i];
                    for (int k = i; k > j; --k) {
                        v[k] = v[k-1];
                        ++num;
                    }
                    v[j] = tmp;
                    break;
                }
            }
        }
        cout << n << " " << num << "\n";
    }
}