#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i] * b[N - i - 1];
    }
    cout << sum;
}