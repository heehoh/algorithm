#include <iostream>
using namespace std;
int main() {
    int N; cin >> N;
    int v[1001];
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= N; i++) {
        v[i] = v[i-1] + v[i-2];
        v[i] %= 10007;
    }
    cout << v[N];
}