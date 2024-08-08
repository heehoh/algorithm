#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s; cin >> s;
    vector<int> v(s.length());
    for (int i = 0; i < s.length(); i++) {
        v[i] = s[i] - '0';
    }
    sort(v.begin(), v.end(), greater());
    for (auto a : v) {
        cout << a;
    }
}