#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, l; cin >> k >> l;
    unordered_map<string, int> m;
    for (int i = 0; i < l; i++) {
        string s; cin >> s;
        m[s] = i;
    }
    vector<pair<string, int>> v;
    for (auto &s : m) {
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        if (i == k)
            break;
        cout << v[i].first << "\n";
    }
}