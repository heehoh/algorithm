#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> two;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            two.push_back(v[i] + v[j]);
        }
    }
    sort(two.begin(), two.end());
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            if (binary_search(two.begin(), two.end(), v[i] - v[j])) {
                cout << v[i];
                return 0;
            }
        }
    }
}