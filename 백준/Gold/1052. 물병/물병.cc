#include <iostream>

using namespace std;
int n, k;

int main() {
    cin >> n >> k;
    int buy = 0;
    for (buy;;buy++) {
        int tmp = n + buy;
        int cnt = 0;
        while (tmp) {
            if (tmp % 2 == 1) {
                ++cnt;
            }
            tmp /= 2;
        }
        if (cnt <= k) break;
    }
    cout << buy;
}