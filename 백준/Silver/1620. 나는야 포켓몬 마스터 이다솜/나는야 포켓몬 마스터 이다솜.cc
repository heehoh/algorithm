#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<string> v(N);
    unordered_map<string, int> m;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        m[v[i]] = i + 1;
    }
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            cout << v[stoi(s) - 1] << "\n";
        } else {
            cout << m[s] << '\n';
        }
    }
}