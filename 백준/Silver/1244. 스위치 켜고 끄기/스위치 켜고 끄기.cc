#include <iostream>
using namespace std;
int light[101];
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> light[i];
    }
    int M; cin >> M;
    while (M--) {
        int x, spot; cin >> x >> spot;
        if (x == 1) {
            for (int i = spot; i <= N; i += spot) {
                if (light[i]) light[i] = 0;
                else light[i] = 1;
            }
        } else {
            int st = spot - 1;
            int en = spot + 1;
            while (st >= 1 && en <= N) {
                if (light[st] != light[en]) break;
                --st;
                ++en;
            }
            for (int i = st + 1; i < en; i++) {
                if (light[i]) light[i] = 0;
                else light[i] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << light[i];
        if (i % 20 == 0) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }
}