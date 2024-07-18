#include <iostream>

using namespace std;
int num[1001];

int main() {
    int n; cin >> n;
    num[1] = 1;
    num[2] = 3;
    for (int i = 3; i <= n; i++) {
        num[i] = num[i - 1] + 2 * num[i - 2];
        num[i] %= 10007;
    }
    cout << num[n] % 10007;
}