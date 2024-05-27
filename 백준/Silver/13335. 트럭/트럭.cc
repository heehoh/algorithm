#include <iostream>
#include <vector>

using namespace std;

int n, w, L;

int check(vector<int> &t) {
    static int i = 0;
    if (i == t.size() - 1 && t[i] == 0) {
        return 0;
    }
    if (t[i] == 0)
        ++i;
    return 1;
}

int main() {
    cin >> n >> w >> L;
    vector<int> a(n); // n번째 트럭의 무게
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i] = w;
    }
    int time = 0;
    while (check(t)) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == 0)
                continue;
            sum += a[i];
            if (sum > L) {
                break;
            }
            if (t[i] == w) {
                --t[i];
                break;
            }
            --t[i];
        }
        ++time;
    }
    cout << time + 1;
}