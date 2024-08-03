#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    unordered_map<string, string> m;
    unordered_map<string, vector<string>> teams;
    int N, M; cin >> N >> M;
    while (N--) {
        string team_name; cin >> team_name;
        int n; cin >> n;
        vector<string> team(n);
        for (int i = 0; i < n; i++) {
            cin >> team[i];
            m[team[i]] = team_name;
        }
        sort(team.begin(), team.end());
        teams[team_name] = team;
    }
    while (M--) {
        string s; cin >> s;
        int n; cin >> n;
        if (n == 0) {
            for (auto s : teams[s]) {
                cout << s << "\n";
            }
        } else {
            cout << m[s] << "\n";
        }
    }
}