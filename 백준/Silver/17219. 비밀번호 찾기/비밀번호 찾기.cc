#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    unordered_map<string, string> m;
    for (int i = 0; i < N; i++) {
        string s1, s2; cin >> s1 >> s2;
        m[s1] = s2;
    }
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        cout << m[s] << "\n";
    }
}